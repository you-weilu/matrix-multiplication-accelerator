from sw_model.signal import AXIStream, Signal
from sw_model.parser import Parser
from sw_model.bram import BRAM
from sw_model.fifo import FIFO
import numpy as np




#Declare Test Data. Make calculations of test matrices. to check against our systolic setup

#Skip over mac recieving packets for now

#Since we know each packets data bytes will be a matrix

A = np.random.randint(-128,127,(16,16), dtype = np.int8)
B = np.random.randint(-128,127,(16,16), dtype = np.int8)
expected_val = A @ B

