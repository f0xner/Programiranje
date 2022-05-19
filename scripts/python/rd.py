#!/usr/bin/python3

import datetime as dt
import os

today = dt.datetime.now().strftime("%Y/%m/%d")
print(today)
if today == "2022/01/02":
    os.system("curl https://imgr.search.brave.com/LnGdrOn0fQpIHxlWBw3tPlE7WQ3HNjtvMPwmUkMrudY/fit/1200/720/ce/1/aHR0cHM6Ly9pLnl0/aW1nLmNvbS92aS96/UVZoZEFJcEZQWS9t/YXhyZXNkZWZhdWx0/LmpwZw --output slika.png")
    print("Odpri sliko,... presenecenje!!")