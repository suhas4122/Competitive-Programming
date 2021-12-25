import numpy_financial as npf
import numpy as np
import tkinter as tk

root= tk.Tk()

canvas1 = tk.Canvas(root, width = 470, height = 480)
canvas1.pack()

label1 = tk.Label(root, text='Calculate Bond Duration')
label1.config(font=('helvetica', 14))
canvas1.create_window(235, 40, window=label1)

entry2 = tk.Entry (root) 
canvas1.create_window(330, 140, window=entry2)

entry3 = tk.Entry (root) 
canvas1.create_window(330, 180, window=entry3)

entry4 = tk.Entry (root) 
canvas1.create_window(330, 220, window=entry4)

entry5 = tk.Entry (root) 
canvas1.create_window(330, 260, window=entry5)

entry6 = tk.Entry (root) 
canvas1.create_window(240, 380, window=entry6)

entry6 = tk.Entry (root) 
canvas1.create_window(240, 420, window=entry6)

label2 = tk.Label(root, text='Number of Years to Maturity:')
label2.config(font=('helvetica', 10))
canvas1.create_window(160, 140, window=label2)

label3 = tk.Label(root, text='Market Price of Bond:')
label3.config(font=('helvetica', 10))
canvas1.create_window(160, 180, window=label3)

label4 = tk.Label(root, text='Face Value:')
label4.config(font=('helvetica', 10))
canvas1.create_window(160, 220, window=label4)

label5 = tk.Label(root, text='Coupon Rate:')
label5.config(font=('helvetica', 10))
canvas1.create_window(160, 260, window=label5)

label6 = tk.Label(root, text='Yeild To Maturity:')
label6.config(font=('helvetica', 10))
canvas1.create_window(115, 380, window=label6)

label7 = tk.Label(root, text='Modified Duration:  ')
label7.config(font=('helvetica', 10))
canvas1.create_window(115, 420, window=label7)

def calcBondPrice():  
    m = 1
    t = float(entry2.get())
    mp = float(entry3.get())
    fv = float(entry4.get())
    c = float(entry5.get())/100
    
    ytm = (c*fv + (fv-mp)/ t) / ((fv + mp)/2)
    pv = ((fv*c/m*(1-(1+ytm/m)**(-m*t)))/(ytm/m)) + fv*(1+(ytm/m))**(-m*t)
    final_year = (t*fv)/(pv*(1+(ytm/m))**(m*t))
    sum_dur = 0
    x = 1

    while x <= m*t:
        tn = x/m
        x = x + 1
        dur = (fv*c*tn)/(pv*m*(1+(ytm/m))**(m*tn))
        sum_dur = sum_dur + dur
    
    #macaulayDuration
    label8 = tk.Label(root, text= ytm,font=('helvetica', 10, 'bold'),bg='white')
    canvas1.create_window(240, 380, window=label8)
     
    #modifiedDuration
    label9 = tk.Label(root, text= (sum_dur+final_year)/(1+ytm/m),font=('helvetica', 10, 'bold'),bg='white')
    canvas1.create_window(240, 420, window=label9)
        
button1 = tk.Button(text='Calculate Bond Duration', command=calcBondPrice, bg='green', fg='white', font=('helvetica', 9, 'bold'))
canvas1.create_window(240, 320, window=button1)

root.mainloop()