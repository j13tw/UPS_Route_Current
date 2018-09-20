import os, sys

# windows only boot up system
os.system("start python Power_Monitor_A.py")
os.system("start python Power_Monitor_B.py")

# linux boot up system
#   os.system('gnome-terminal -x sh -c "python3 Power_Monitor_A.py"')
#   os.system('gnome-terminal -x sh -c "python3 Power_Monitor_B.py"')