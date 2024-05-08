#ifndef FIRWEIGHTS_H
#define FIRWEIGHTS

#define FIR1LENGTH 101
#define FIR2LENGTH 101
#define FIR3LENGTH 101

static __attribute__((aligned(16))) float FIR1WEIGHTS[FIR1LENGTH] = 
	{0.000022,-0.000109,-0.000247,-0.000391,-0.000539,-0.000682,-0.000810,-0.000908,-0.000957,-0.000936,-0.000824,-0.000607,-0.000272,0.000181,0.000741,0.001384,0.002070,0.002747,0.003352,0.003813,0.004058,0.004016,0.003632,0.002863,0.001698,0.000150,-0.001727,-0.003848,-0.006090,-0.008297,-0.010291,-0.011876,-0.012851,-0.013025,-0.012225,-0.010315,-0.007207,-0.002866,0.002675,0.009320,0.016903,0.025198,0.033926,0.042769,0.051382,0.059416,0.066532,0.072424,0.076831,0.079557,0.080480,0.079557,0.076831,0.072424,0.066532,0.059416,0.051382,0.042769,0.033926,0.025198,0.016903,0.009320,0.002675,-0.002866,-0.007207,-0.010315,-0.012225,-0.013025,-0.012851,-0.011876,-0.010291,-0.008297,-0.006090,-0.003848,-0.001727,0.000150,0.001698,0.002863,0.003632,0.004016,0.004058,0.003813,0.003352,0.002747,0.002070,0.001384,0.000741,0.000181,-0.000272,-0.000607,-0.000824,-0.000936,-0.000957,-0.000908,-0.000810,-0.000682,-0.000539,-0.000391,-0.000247,-0.000109,0.000022};

static __attribute__((aligned(16))) float FIR2WEIGHTS[FIR2LENGTH] = 
	{-0.000121,-0.000347,-0.000409,-0.000299,-0.000067,0.000181,0.000301,0.000146,-0.000366,-0.001197,-0.002163,-0.002962,-0.003265,-0.002852,-0.001732,-0.000190,0.001267,0.002090,0.001918,0.000788,-0.000790,-0.001947,-0.001752,0.000392,0.004416,0.009450,0.014003,0.016432,0.015560,0.011220,0.004490,-0.002530,-0.007400,-0.008265,-0.004727,0.001718,0.007895,0.009870,0.004336,-0.009977,-0.031363,-0.055086,-0.074366,-0.082193,-0.073484,-0.046914,-0.005796,0.042338,0.087434,0.119453,0.131027,0.119453,0.087434,0.042338,-0.005796,-0.046914,-0.073484,-0.082193,-0.074366,-0.055086,-0.031363,-0.009977,0.004336,0.009870,0.007895,0.001718,-0.004727,-0.008265,-0.007400,-0.002530,0.004490,0.011220,0.015560,0.016432,0.014003,0.009450,0.004416,0.000392,-0.001752,-0.001947,-0.000790,0.000788,0.001918,0.002090,0.001267,-0.000190,-0.001732,-0.002852,-0.003265,-0.002962,-0.002163,-0.001197,-0.000366,0.000146,0.000301,0.000181,-0.000067,-0.000299,-0.000409,-0.000347,-0.000121};

static __attribute__((aligned(16))) float FIR3WEIGHTS[FIR3LENGTH] = 
	{-0.000000,-0.000282,-0.000502,-0.000592,-0.000504,-0.000224,0.000202,0.000668,0.001019,0.001094,0.000785,0.000095,-0.000826,-0.001697,-0.002177,-0.001983,-0.001011,0.000575,0.002343,0.003686,0.004014,0.002977,0.000646,-0.002421,-0.005283,-0.006874,-0.006370,-0.003521,0.001135,0.006322,0.010324,0.011509,0.008907,0.002672,-0.005759,-0.013910,-0.018904,-0.018340,-0.011184,0.001625,0.017064,0.030525,0.036855,0.031692,0.012765,-0.019227,-0.060420,-0.104394,-0.143464,-0.170379,0.819879,-0.170379,-0.143464,-0.104394,-0.060420,-0.019227,0.012765,0.031692,0.036855,0.030525,0.017064,0.001625,-0.011184,-0.018340,-0.018904,-0.013910,-0.005759,0.002672,0.008907,0.011509,0.010324,0.006322,0.001135,-0.003521,-0.006370,-0.006874,-0.005283,-0.002421,0.000646,0.002977,0.004014,0.003686,0.002343,0.000575,-0.001011,-0.001983,-0.002177,-0.001697,-0.000826,0.000095,0.000785,0.001094,0.001019,0.000668,0.000202,-0.000224,-0.000504,-0.000592,-0.000502,-0.000282,-0.000000};

#endif // FIRWEIGHTS_H