#include <NewPing.h> 
 
 
 
// Pin Definitions based on Chapter 4 
 
 
 
#define LEFT_TRIG 2 
 
 
 
#define LEFT_ECHO 3 
 
 
 
#define CENTER_TRIG 4 
 
 
 
#define CENTER_ECHO 5 
 
 
 
#define RIGHT_TRIG 6 
 
 
 
#define RIGHT_ECHO 7 
 
 
 
#define MAX_DIST 400 // Maximum distance in cm 
 
 
 
#define ALPHA 0.6 // Smoothing factor for EMA 
 
 
// Initialize Sensors 
NewPing sonarL(LEFT_TRIG, LEFT_ECHO, MAX_DIST); 
 
 
NewPing sonarC(CENTER_TRIG, CENTER_ECHO, MAX_DIST); 
 
 
 
NewPing sonarR(RIGHT_TRIG, RIGHT_ECHO, MAX_DIST); 
 
 
 
// Variables for Filtered Data 
 
 
 
float fL = 400.0, fC = 400.0, fR = 400.0; 
 
 
 
void setup () { 
 
 
 
Serial.begin(115200); // High-speed Serial for Pi communication 
 
 
 
} 
 
 
 
void loop () { 
 
 
 
// 1. Read Raw Values 
 
 
 
int rL = sonarL.ping_cm(); 
 
 
 
int rC = sonarC.ping_cm(); 
 
 
 
int rR = sonarR.ping_cm(); 
 
 
// 2. Handle Zeroes (Timeout/No Echo) 
 
 
 
if (rL == 0) rL = MAX_DIST; 
 
 
 
if (rC == 0) rC = MAX_DIST; 
 
 
 
if (rR == 0) rR = MAX_DIST; 
 
 
 
// 3. Exponential Moving Average (EMA) Filtering 
 
 
 
fL = (ALPHA * rL) + ((1.0 - ALPHA) * fL); 
 
 
 
fC = (ALPHA * rC) + ((1.0 - ALPHA) * fC); 
 
 
 
fR = (ALPHA * rR) + ((1.0 - ALPHA) * fR); 
 
 
 
// 4. Send CSV Packet: L, C,R\n 
 
 
 
Serial.print((int)fL); Serial.print(","); 
 
Serial.print((int)fC); Serial.print(","); 
 
 
Serial.println((int)fR); 
delay(35); // Prevent acoustic cross-talk 
} 
 
Technical Explanation: 
 
 
 
•	Smoothing Algorithm: The ALPHA variable controls how much weight is given 
 
 
 
to the new reading versus previous data. A value of 0.6 ensures the robot 
 
 
 
ignores momentary signal "spikes" while remaining responsive to obstacles. 
 
 
 
•	CSV Framing: The distances are converted to integers and joined by commas. 
 
 
 
The println function adds a \n character, allowing the Raspberry Pi to recognize 
 
 
 
the end of a data packet. 
