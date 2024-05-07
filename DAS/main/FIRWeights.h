#ifndef FIRWEIGHTS_H
#define FIRWEIGHTS

#define FIR1LENGTH 101
#define FIR2LENGTH 101
#define FIR3LENGTH 101

static __attribute__((aligned(16))) float FIR1WEIGHTS[FIR1LENGTH] = 
	{0.000022,-0.000109,-0.000247,-0.000391,-0.000539,-0.000682,-0.000810,-0.000908,-0.000957,-0.000936,-0.000824,-0.000607,-0.000272,0.000181,0.000741,0.001384,0.002070,0.002747,0.003352,0.003813,0.004058,0.004016,0.003632,0.002863,0.001698,0.000150,-0.001727,-0.003848,-0.006090,-0.008297,-0.010291,-0.011876,-0.012851,-0.013025,-0.012225,-0.010315,-0.007207,-0.002866,0.002675,0.009320,0.016903,0.025198,0.033926,0.042769,0.051382,0.059416,0.066532,0.072424,0.076831,0.079557,0.080480,0.079557,0.076831,0.072424,0.066532,0.059416,0.051382,0.042769,0.033926,0.025198,0.016903,0.009320,0.002675,-0.002866,-0.007207,-0.010315,-0.012225,-0.013025,-0.012851,-0.011876,-0.010291,-0.008297,-0.006090,-0.003848,-0.001727,0.000150,0.001698,0.002863,0.003632,0.004016,0.004058,0.003813,0.003352,0.002747,0.002070,0.001384,0.000741,0.000181,-0.000272,-0.000607,-0.000824,-0.000936,-0.000957,-0.000908,-0.000810,-0.000682,-0.000539,-0.000391,-0.000247,-0.000109,0.000022};

static __attribute__((aligned(16))) float FIR2WEIGHTS[FIR2LENGTH] = 
	{0.000697,0.000699,0.000550,0.000238,-0.000211,-0.000736,-0.001238,-0.001598,-0.001709,-0.001519,-0.001065,-0.000487,-0.000002,0.000155,-0.000183,-0.001023,-0.002168,-0.003225,-0.003694,-0.003117,-0.001246,0.001818,0.005579,0.009223,0.011819,0.012591,0.011197,0.007908,0.003613,-0.000374,-0.002689,-0.002368,0.000739,0.005760,0.010872,0.013693,0.011917,0.004053,-0.009951,-0.028390,-0.047923,-0.064157,-0.072605,-0.069790,-0.054219,-0.026983,0.008226,0.045720,0.078917,0.101720,0.109837,0.101720,0.078917,0.045720,0.008226,-0.026983,-0.054219,-0.069790,-0.072605,-0.064157,-0.047923,-0.028390,-0.009951,0.004053,0.011917,0.013693,0.010872,0.005760,0.000739,-0.002368,-0.002689,-0.000374,0.003613,0.007908,0.011197,0.012591,0.011819,0.009223,0.005579,0.001818,-0.001246,-0.003117,-0.003694,-0.003225,-0.002168,-0.001023,-0.000183,0.000155,-0.000002,-0.000487,-0.001065,-0.001519,-0.001709,-0.001598,-0.001238,-0.000736,-0.000211,0.000238,0.000550,0.000699,0.000697};

static __attribute__((aligned(16))) float FIR3WEIGHTS[FIR3LENGTH] = 
	{0.000087,0.000327,0.000511,0.000594,0.000540,0.000331,-0.000021,-0.000459,-0.000886,-0.001176,-0.001202,-0.000880,-0.000207,0.000715,0.001678,0.002406,0.002621,0.002130,0.000904,-0.000875,-0.002819,-0.004404,-0.005094,-0.004499,-0.002514,0.000589,0.004167,0.007312,0.009060,0.008648,0.005764,0.000718,-0.005528,-0.011500,-0.015508,-0.016061,-0.012291,-0.004296,0.006696,0.018418,0.027906,0.032049,0.028247,0.015032,-0.007482,-0.037437,-0.071418,-0.104962,-0.133311,-0.152257,0.841127,-0.152257,-0.133311,-0.104962,-0.071418,-0.037437,-0.007482,0.015032,0.028247,0.032049,0.027906,0.018418,0.006696,-0.004296,-0.012291,-0.016061,-0.015508,-0.011500,-0.005528,0.000718,0.005764,0.008648,0.009060,0.007312,0.004167,0.000589,-0.002514,-0.004499,-0.005094,-0.004404,-0.002819,-0.000875,0.000904,0.002130,0.002621,0.002406,0.001678,0.000715,-0.000207,-0.000880,-0.001202,-0.001176,-0.000886,-0.000459,-0.000021,0.000331,0.000540,0.000594,0.000511,0.000327,0.000087};

#endif // FIRWEIGHTS_H
