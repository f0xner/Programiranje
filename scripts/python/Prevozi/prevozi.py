#!/usr/bin/python3
import requests as r
import json
converted = ""
def getNew():
    url = "https://prevoz.org/api/search/shares/?f=Ljubljana&fc=SI&t=Koper&tc=SI&d=2022-02-11&exact=false&intl=false"
    response = r.get(url)
    converted = response.json().get("carshare_list")
def fromJson():
    ret = ""
    with open("testResponse.json") as f:
        ret = json.load(f)
    return ret
        
converted = fromJson()
for id in converted["data"]:
    if "Koper" == id["to"] and 5 == id["price"] and 17 <= int(id["time"][3:5]) and id["price"]<=5:
        print(id["time"][3:],id["price"],"kontakt:",id["contact"])


