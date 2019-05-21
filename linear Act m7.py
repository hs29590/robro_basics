
import utime
from pyb import Servo

s1 = Servo(1) # P7
def extendFull():
    s1.pulse_width(2000)
    utime.sleep(12)
def retractFull():
    s1.pulse_width(1000)
    utime.sleep(12)
def extendDistance(n):
    if(n<=140):
        pulseTime=int((1000+((50*n)/7)))
        actDelay=int(((12000*n)/140))
        s1.pulse_width(pulseTime)
        utime.sleep(actDelay)
i=1
while(i==1):
        extendFull()
        retractFull()
        extendDistance(100)
        i=i+1
