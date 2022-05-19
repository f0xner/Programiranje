import requests as r
from bs4 import BeautifulSoup as BS
import re
import sys
# url = "https://www.bestwordlist.com/5letterwords.htm"
# ret = r.get("https://www.bestwordlist.com/5letterwords.htm")
# soup = BS(ret.content,"html5lib")
# span = soup.select(".mot, .mot2")
# for i in range(0,len(span)):
#     span[i] = span[i].text.strip().split()
# final = [beseda for sp in span for beseda in sp]
# def f(url):
#     ret = r.get(url)
#     soup = BS(ret.content,"html5lib")
#     span = []
#     span = soup.select(".mot, .mot2")
#     for i in range(0,len(span)):
#         span[i] = span[i].text.strip().split()
#     span = [beseda for sp in span for beseda in sp]
#     return span
# for i in range(2,16):
#     final.append(f(f"https://www.bestwordlist.com/5letterwordspage{i}.htm"))
# final = [beseda for sp in final for beseda in sp]

with open("besede.txt","r") as f:
    final = []
    for line in f:
        final.append(line[:-1])
# with open("besede2.txt","r") as f:
#     for line in f:
#         final.append(line[:-1])
# final.sort()
# with open("besede.txt","w") as f:
#     for beseda in final:
#         f.write('%s\n'%beseda)
def poisci(str):
    zadetki = []
    for beseda in final:
       zadetek = re.findall(str,beseda)
       if zadetek != []:
           zadetki.append(zadetek)
    print(zadetki)
    return zadetki
poisci(sys.argv[1])