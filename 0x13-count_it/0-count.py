#!/usr/bin/python3
"""
This module contains a program that parses the title of all hot
articles, and prints a sorted count of given keywords
"""
import json
import re
import requests
import time


def elements_count(request, list_of_words, results):
    """counts number of elements"""
    for title in request['data']['children']:
        datas = title['data']['title'].split(" ")
        for i in range(len(datas)):
            datas[i] = datas[i].lower()
            if(datas[i] in list_of_words):
                if(datas[i] in results.key()):
                    results[datas[i]] += list_of_words.count(datas[i])
                else:
                    results[datas[i]] = list_of_words.count(datas[i])
    return results


def words_count(subreddit, word_list, results={}, param={'limit': 100}):
    """ recursive method that counts number of elements """
    baseLink = 'https://api.reddit.com/r/%s/hot.json' % subreddit

    if ('after' not in param):
        word_list = [str.lower() for str in word_list]

    link = baseLink
    customHeaders = {'User-agent': 'HolbertonSchoolTask'}
    r = requests.get(link, headers=customHeaders,
                     params=param, allow_redirects=False)

    if (r.status_code != 200):
        return
    data = r.content

    data = json.loads(data.decode('utf-8'))
    param = {'limit': 100, 'count': 100, 'after': data['data'].get('after')}
    if (data['data'].get('after') is None):
        results = elements_count(data, word_list, results)
        results = sorted(
            results.items(), key=lambda x: (-x[1], x[0]), reverse=False
            )
        for i in results:
            print("{}: {}".format(i[0], i[1]))
    else:
        results = elements_count(data, word_list, results)
        words_count(subreddit, word_list, results, param)
