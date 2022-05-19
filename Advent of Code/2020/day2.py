#!/usr/bin/python3
pcps = []
valid_passwords = 0
with open("day2IN") as file:
    pcps = file.readlines()
    pcps = [pcp.rstrip() for pcp in pcps]

for i in range(0, len(pcps), 1):
    lmcp = pcps[i].split(": ")
    lmc = lmcp[0].split(" ")
    # najmanj kolko krat se mora chr_tr ponovit
    least = int(lmc[0].split("-")[0])
    # največ kolko krat se mora chr_tr ponovit
    most = int(lmc[0].split("-")[1])
    chr_tr = lmc[1]  # črka ki se mora [least,most] ponovit
    password = lmcp[1]  # geslo kjer se mora chr_tr ponovit
    ponovitev = 0
    # === part 1 ===
    # for ch in password:
    #     if ch == chr_tr:
    #         ponovitev+=1
    # if ponovitev >= least and ponovitev<=most:
    #     valid_passwords+=1
    # === part 2 ===
    prvi = False
    drugi = False
    # if password[least-1] == chr_tr:
    #     prvi = True
    # if password[most-1] == chr_tr:
    #     drugi = True
    # if prvi != drugi:
    #     valid_passwords += 1

print(valid_passwords)
