#!/usr/bin/python3
import requests
units = 480
villages = [26385,13428]
carry = units*25
option = 2
cookies = {"cid":"2122782877",
           "en_auth":"b26a4d358967:466925209473dd97e321400e8a49719c695dafe82e37e5cf3ecb927db1e87147",
           "sid":"0:5ae76df20f9f3663f28aa80dde75b62f0333abb92a47b1f9e01a954dd67b3753fa4064f00d08362163c2863fd869cde1253f4e73a3ced776883ca405e6d1e12c",
           "global_village_id":str(villages[1]),
           "websocket_available":"True",
           "io":"_HJ36EP3Ayq_pEv4A-LS"}
qsp = {"village":str(villages[1]),
        "screen":"scavenge_api",
        "ajaxaction":"send_squads"}
formData = {"squad_request[0][village_id]":str(villages[1]),
            "squad_requests[0][candidate_squad][unit_counts][spear]":str(units),
            "squad_requests[0][candidate_squad][carry_max]":str(carry),
            "squad_requests[0][option_id]":str(option),
            "squad_requests[0][use_premium]":"False",
            "h":"b216bb21"}
headers = {"authority":"en124.tribalwars.net",
           "path":"/game.php?village=13428&screen=scavenge_api&ajaxaction=send_squads",
           "scheme":"https",
           "accept":"application/json, text/javascript, */*; q=0.01",
           "accept-encoding":"gzip, deflate, br",
           "accept-language":"en-US,en;q=0.9",
           "content-type":"application/x-www-form-urlencoded; charset=UTF-8",
           "dnt":"1",
           "origin":"https://en124.tribalwars.net",
           "refer":"https://en124.tribalwars.net/game.php?village=13428&screen=place&mode=scavenge",
           "sec-fetch-dest":"empty",
           "sec-fetch-mode":"cors",
           "sec-fetch-site":"same-origin",
           "sec-gpc":"1",
           "tribalwars-ajax":"1",
           "user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.79 Safari/537.36",
           "x-requested-with":"XMLHttpRequest"}
url= "https://en124.tribalwars.net/game.php?village=13428&screen=scavenge_api&ajaxaction=send_squads"
r = requests.post(url=url,cookies=cookies,params=qsp,data=formData,headers=headers)
print(r.status_code)