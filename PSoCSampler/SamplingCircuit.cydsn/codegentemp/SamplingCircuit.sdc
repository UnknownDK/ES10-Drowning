# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\tardi\Desktop\ES10-Drowning\PSoCSampler\SamplingCircuit.cydsn\SamplingCircuit.cyprj
# Date: Mon, 15 Apr 2024 06:48:59 GMT
#set_units -time ns
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_0}]]


# Component constraints for C:\Users\tardi\Desktop\ES10-Drowning\PSoCSampler\SamplingCircuit.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\tardi\Desktop\ES10-Drowning\PSoCSampler\SamplingCircuit.cydsn\SamplingCircuit.cyprj
# Date: Mon, 15 Apr 2024 06:48:57 GMT
