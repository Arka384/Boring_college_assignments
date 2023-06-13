dict = {}
dict["Monday"] = ("cp_m123", "5%")
dict["Tuesday"] = ("cp_yu253", "6%")
dict["Wednesday"] = ("cp_we564", "2%")
dict["Thurseday"] = ("cp_ts89", "3%")
dict["Friday"] = ("cp_fd990", "10%")
dict["Saturday"] = ("cp_sx343", "4%")
dict["Sunday"] = ("cp_snd893", "8%")

while True:
    day=input("Find coupon for day: ")
    if(day == "exit"):
        break
    print(dict.get(day, "Invalid day"))


