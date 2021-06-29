import tkinter as tk
from tkinter.constants import BOTH, BOTTOM, LEFT, RIGHT, TOP, X, Y
from typing import Collection
import tk_tools
from decimal import Decimal
from datetime import datetime

# initialization of some variables for gauges
count = 0
up = True
max_speed=240

print(datetime.now().strftime('%A, %d %B %Y\n'))
print("LOADING DASHBOARD, PLEASE WAIT...")

#Define init for main window
def init(win):
    win.title("SolarTuk Dashboard")
    win.attributes('-fullscreen', True)
    win.config(background = "#545454")

def top_bar(win):
    label_top_st = tk.Label(label_top, text="SolarTuk",fg='white',bg='#474747',font=('Arial', 16))
    label_top_lblink = tk.Canvas(label_top, height= 30, width=30, bg='#474747', highlightthickness=0)
    label_top_rblink = tk.Canvas(label_top, bg='#474747', highlightthickness=0)
    label_top_date = tk.Label(label_top, text=datetime.now().strftime('%A, %d %B %Y'),fg='white',bg='#474747',font=('Arial', 8))

    label_top_st.place(x=15, y=20)

    label_top_lblink.place(x=235, y=10)
    led_l = tk_tools.Led(label_top_lblink, size=40, toggle_on_click=True)
    led_l.to_green()
    led_l.pack(fill=BOTH)
    
    label_top_rblink.place(x=510, y=10)
    led_r = tk_tools.Led(label_top_rblink, size=40, toggle_on_click=True)
    led_r.to_green()
    led_r.pack(fill=BOTH)

    label_top_date.place(x=650, y=25)

def left_bottom(root):
    cRPM = tk.Canvas(root, width=120, bg='#616161', highlightthickness=0)
    cRPM.grid(row=0, column=0, columnspan=3, padx=5, pady=20, sticky='nsew')

    cLed1 = tk.Canvas(root, width=50, highlightthickness=0)
    cLed2 = tk.Canvas(root, width=50, highlightthickness=0)
    cLed3 = tk.Canvas(root, width=50, highlightthickness=0)
    cLed1.grid(row=1, column=0, padx=5,pady=5, sticky='nsew')
    cLed2.grid(row=1, column=1, padx=5,pady=5, sticky='nsew')
    cLed3.grid(row=1, column=2, padx=5,pady=5, sticky='nsew')

    cBatPerc = tk.Canvas(root, width=120, bg='#616161', highlightthickness=0)
    cBatPerc.grid(row=2, column=0, columnspan=3, padx=5,pady=20, sticky='nsew')

    tach_gauge = tk_tools.Gauge(cRPM, max_value=5000,label='TACHO',unit=' RPM',divisions=10, bg='#616161')
    tach_gauge.pack(fill=BOTH)

    led_l = tk_tools.Led(cLed1, size=40, toggle_on_click=True)
    led_l.to_red()
    led_l.pack(fill=BOTH)
    led_m = tk_tools.Led(cLed2, size=40, toggle_on_click=True)
    led_m.to_green()
    led_m.pack(fill=BOTH)
    led_r = tk_tools.Led(cLed3, size=40, toggle_on_click=True)
    led_r.to_yellow()
    led_r.pack(fill=BOTH)

    perc_gauge = tk_tools.Gauge(cBatPerc, max_value=100, label='Battery %', unit=' %', divisions=10, red= 99, yellow=98, red_low=20, yellow_low=50, bg='#616161')
    perc_gauge.pack(fill=BOTH)
    
def mid_bottom(root):
    speedo = tk_tools.SevenSegmentDigits(root, digits=3, background='#2e2e2e', digit_color='red', height=100)
    speedo.place(x=320, y=80)
    #speedo.set_value(6)

    tk.Label(root, text="THROT", font='Montserrat 8 bold', bg='#616161', fg='#FFFFFF').place(x=290, y=232)
    tk.Label(root, text="BRAKE", font='Montserrat 8 bold', bg='#616161', fg='#FFFFFF').place(x=290, y=262)
    tk.Label(root, text="STEER", font='Montserrat 8 bold', bg='#616161', fg='#FFFFFF').place(x=290, y=292)

    tk.Canvas(root, width=150, height=20, bg="#c7d5e0", bd=0, highlightthickness=0).place(x=350, y=235)
    tk.Canvas(root, width=150, height=20, bg="#c7d5e0", bd=0, highlightthickness=0).place(x=350, y=265)
    tk.Canvas(root, width=150, height=20, bg="#c7d5e0", bd=0, highlightthickness=0).place(x=350, y=295)

    steer_percent = 75
    throttle_percent = 20
    brake_percent = 10

    tk.Canvas(root, width=int(throttle_percent), height=20, bg='green', bd=0, highlightthickness=0).place(x=350, y=235)
    tk.Canvas(root, width=int(brake_percent), height=20, bg='red', bd=0, highlightthickness=0).place(x=350, y=265)
    tk.Canvas(root, width=int(steer_percent), height=20, bg='blue', bd=0, highlightthickness=0).place(x=350, y=295)

def right_bottom(root):
    batV_gauge = tk_tools.Gauge(root, height=120, width=200, max_value=48, min_value= 4, label='Battery V',unit=' V',divisions=10, yellow=70, red=80, red_low=40, yellow_low=50, bg='#616161')
    batV_gauge.place(x=595, y=60)

    batI_gauge = tk_tools.Gauge(root, height=120, width=200, max_value=6, min_value= -8, label='Battery I',unit=' A',divisions=14, yellow=80, red=90, red_low=20, yellow_low=30, bg='#616161')
    batI_gauge.place(x=595, y=220)

def bottom_bar(win):
    label_left = tk.Canvas(label_bottom, height=400, width=150, bg='#616161',highlightthickness=0)
    label_left.pack(fill=BOTH, side=LEFT, expand=True)
    left_bottom(label_left)

    label_mid = tk.Canvas(label_bottom, height=400, bg='#616161', highlightthickness=0)
    label_mid.pack(fill=BOTH, side=LEFT, expand=False)
    mid_bottom(label_bottom)

    label_right = tk.Canvas(label_bottom, height=400, width=150, bg='#616161',highlightthickness=0)
    label_right.pack(fill=BOTH, side=LEFT, expand=True)
    right_bottom(label_bottom)

#Init top-level window
win=tk.Tk()
init(win)

# LAYOUT
label_top = tk.Canvas(win, height=50 ,bg='#474747', highlightthickness=0)
label_top.pack(fill=X, side=TOP, ipady=10)
top_bar(win)

label_bottom = tk.Canvas(win, height=400, bg='#616161', highlightthickness=0)
label_bottom.pack(fill=BOTH, side=TOP)
bottom_bar(win)

#Start main-loop
win.mainloop()
