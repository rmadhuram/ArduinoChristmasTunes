/*
    Christmas tunes with dancing lights  
    by Raj Madhuram ( http://geekraj.com ) 
    
    Adapted the melody code by Tom Igoe
    Notes from various places (acknowledged inline)
    
 */
#include "pitches.h"

typedef struct {
   int *melody;
   int *durations;
   int numCount;
   int tempo;
   int low, high;
} tune;

tune tunes[5];

// Jingle Bells
int jingleBells[] = { N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_E5, N_D5, N_D5, N_E5, N_D5, N_G5,
                      N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_G5, N_G5, N_F5, N_D5, N_C5};
int jingleBellsDurations[] = { 4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 16,
                               4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8,
                               4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 16,
                               4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16 };
                               
// The first noel
// http://www.music-for-music-teachers.com/support-files/first-noel-broken-chord-stretch-key-of-c.pdf

int firstNoel[] = { N_E4, N_D4, N_C4, N_D4, N_E4, N_F4, N_G4, N_A4, N_B4, N_C5, N_B4, N_A4,
                    N_G4, N_A4, N_B4, N_C5, N_B4, N_A4, N_G4, N_A4, N_B4, N_C5, N_G4, N_F4,
                    N_E4, N_E4, N_D4, N_C4, N_D4, N_E4, N_F4, N_G4, N_A4, N_B4, N_C5, N_B4, N_A4,
                    N_G4, N_A4, N_B4, N_C5, N_B4, N_A4, N_G4, N_A4, N_B4, N_C5, N_G4, N_F4,
                    N_E4, N_E4, N_D4, N_C4, N_D4, N_E4, N_F4, N_G4, N_C5, N_B4, N_A4, N_A4,
                    N_G4, N_C5, N_B4, N_A4, N_G4, N_A4, N_B4, N_C5, N_G4, N_F4, N_E4
                  };

int firstNoelDurations[] = { 2, 2, 6, 2, 2, 2, 8, 2, 2, 4, 4, 4,
                             8, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                             8, 2, 2, 6, 2, 2, 2, 8, 2, 2, 4, 4, 4,
                             8, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4,                             
                             8, 2, 2, 6, 2, 2, 2, 8, 2, 2, 8, 4,
                             12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8  };
                             
// O Holy Night
// http://www.music-for-music-teachers.com/support-files/o-holy-night-lead-sheet-c.pdf

int oHolyNight[] = { N_E4, N_E4, N_E4, N_G4, N_REST, N_G4, N_A4, N_A4, N_F4, N_A4, N_C5,
                     N_G4, N_G4, N_E4, N_D4, N_C4, N_E4, N_F4, N_G4, N_F4, N_D4, N_C4,
                     N_E4, N_E4, N_E4, N_G4, N_REST, N_G4, N_A4, N_A4, N_F4, N_A4, N_C5,
                     N_G4, N_G4, N_FS4, N_E4, N_B4, N_G4, N_A4, N_B4, N_C5, N_B4, N_E4, N_REST, N_G4,
                     N_G4, N_A4, N_D4, N_G4, N_A4, N_G4, N_C5, N_E4, N_A4, N_G4, N_G4, N_G4, N_A4,
                     N_D4, N_G4, N_A4, N_G4, N_C5, N_E4, N_G4, N_C5, N_C5, N_B4, N_A4,
                     N_B4, N_A4, N_REST, N_A4, N_D5, N_D5, N_A4, N_A4, N_A4, N_C5,
                     N_C5, N_REST, N_C5, N_E5, N_D5, N_D5, N_G4, N_C5, N_C5, N_B4, N_A4,
                     N_G4, N_G4, N_G4, N_A4, N_G4, N_G4, N_G4, N_C5, N_D5,
                     N_D5, N_G4, N_E5, N_E5, N_D5, N_C5, N_B4, N_C5, N_D5,
                     N_C5 };

int oHolyNightDurations[] = { 6, 4, 2, 8, 2, 2 , 4, 2, 4, 2, 12,
                              4, 2, 4, 2, 6, 4, 2, 6, 4, 2, 24,
                              6, 4, 2, 8, 2, 2 , 4, 2, 4, 2, 12,
                              4, 2, 4, 2, 6, 4, 2, 6, 4, 2, 20, 2, 2,
                              6, 6, 6, 6, 4, 2, 4, 2, 6, 4, 2, 6, 6,
                              6, 6, 4, 2, 4, 2, 12, 12, 6, 4, 2,
                              12, 8, 2, 2, 12, 4, 2, 4, 2, 12,
                              8, 2, 2, 12, 8, 2, 2, 12, 6, 4, 2,
                              12, 4, 2, 4, 2, 12, 6, 6, 12,
                              6, 6, 12, 6, 6, 12, 6, 4, 2,
                              24 };

// http://www.christmas-carol-music.org/Lead_Sheets/WeThreeKings.html

int weThreeKings[] = { N_B4, N_A4, N_G4, N_E4, N_FS4, N_G4, N_FS4, N_E4,
                       N_B4, N_A4, N_G4, N_E4, N_FS4, N_G4, N_FS4, N_E4,
                       N_G4, N_G4, N_G4, N_A4, N_A4, N_B4, N_B4, N_D5, N_C5, N_B4,
                       N_A4, N_B4, N_A4, N_G4, N_FS4, N_E4,
                       N_FS4, N_A4, N_G4, N_G4, N_G4, N_D4, N_G4, N_E4, N_G4, N_G4, N_G4, N_G4, N_D4, N_G4, N_E4, N_G4,
                       N_G4, N_G4, N_A4, N_B4, N_C5, N_B4, N_A4, N_B4, N_G4, N_G4, N_G4, N_D4, N_G4, N_E4, N_G4 };
                       
int weThreeKingsDurations[] = { 4, 2, 4, 2, 2, 2, 2, 6,
                                4, 2, 4, 2, 2, 2, 2, 6,
                                2, 2, 2, 4, 2, 4, 2, 2, 2, 2,
                                2, 2, 2, 4, 2, 6,
                                6, 6, 4, 2, 4, 2, 4, 2, 6, 4, 2, 4, 2, 4, 2, 6,
                                4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 6  };
  
// What child is this
// http://www.free-scores.com/PDF_EN/traditional-what-child-is-this-39593.pdf

int whatChild[] = { N_E4, N_G4, N_A4, N_B4, N_C5, N_B4, N_A4, N_FS4, N_D4, N_E4, N_FS4, N_G4, N_E4, N_E4, N_DS4, N_E4, N_FS4, N_B3, N_REST,  N_E4,
                    N_G4, N_A4, N_B4, N_C4, N_B4, N_A4, N_FS4, N_D4, N_E4, N_FS4, N_G4, N_FS4, N_E4, N_DS4, N_CS4, N_D4, N_E4, N_E4, N_REST,
                    N_D5, N_D5, N_C5, N_B4, N_A4, N_FS4, N_D4, N_E4, N_FS4, N_G4, N_E4, N_E4, N_DS4, N_E4, N_FS4, N_DS4, N_B3, N_REST, 
                    N_D5, N_D5, N_C5, N_B4, N_A4, N_FS4, N_D4, N_E4, N_FS4, N_G4, N_FS4, N_E4, N_DS4, N_CS4, N_D4, N_E4, N_E4} ;

int whatChildDurations[] = { 2, 4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 6, 2, 2, 2,
                             4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 6, 4, 2,
                             6, 3, 1, 2, 4, 2, 3, 1, 2, 4, 2, 3, 1, 2, 4, 2, 4, 2,
                             6, 3, 1, 2, 4, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 6, 4};
  
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;
int toneNum = 0;  
int randomOffset = 0;
int outputStartPin = 3;
int continuousMode = 0;

void play(int tuneNum) {
  
  randomOffset = random(32);
    
  int numNotes = tunes[tuneNum].numCount;
  int tempo = tunes[tuneNum].tempo;
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    
    int freq = tunes[tuneNum].melody[thisNote]*2;
    int noteDuration = tempo*tunes[tuneNum].durations[thisNote];
    
    if (freq > 0) {
       int n = (map(freq, tunes[tuneNum].low, tunes[tuneNum].high, 1, 31) + randomOffset)%31 + 1; 
       lightsUp(n);
       tone(8, freq, noteDuration);
       
    } else {
       // REST
       delay(noteDuration);
    }

    delay(noteDuration);
    blankLights();
    
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 0.30;    
    delay(pauseBetweenNotes);    
    
    noTone(8);
     
  }  
}

void lightSweep(int k, int nBits) {
  for (int i=0; i<5; i++) {
    lightsUp(k);
    delay(50);
    k = k<<1;
    blankLights();
    delay(20);
  }
  
  k = k>>nBits;
  
  for (int i=0; i<5; i++) {
    lightsUp(k);
    delay(50);
    k = k>>1;
    blankLights();
    delay(20);
  }  
}

void fromCenter() {
  for (int i=0; i<2; i++) {
    lightsUp(4);
    delay(50);
    blankLights();
    delay(50);
  }
  
  for (int i=0; i<4; i++) {
    lightsUp(10);
    delay(50);
    blankLights();
    delay(50);
  }
  
  lightsUp(31);
  delay(100);
  blankLights();
}

void lightEffect(int n) {
  switch(n) {
     case 0: for (int i=0; i<2; i++) { lightSweep(1, 1); }
             break;        
             
     case 1: for (int i=0; i<2; i++) { lightSweep(7, 2); }
             break;        
          
     case 2: for (int i=0; i<2; i++) { lightSweep(5, 2); }
             break;   
             
     case 3: for (int i=0; i<2; i++) { fromCenter(); }
             break;               
  }
}

void lightsUp(int n) {
  int i = 0;
  while (n>0 && i<5) {
    if (n%2 == 1) {
      digitalWrite(outputStartPin+i, HIGH);            
    } else {
      digitalWrite(outputStartPin+i, LOW);
    }
    n = n>>1; 
    i++;
  }
}

void blankLights() {
  for (int i=0; i<5; i++) {
    digitalWrite(i+outputStartPin, LOW); 
  }
}

void setup() {
  
  int numTunes = 5;
  
  tunes[0].melody = jingleBells;
  tunes[0].durations = jingleBellsDurations;
  tunes[0].numCount = sizeof(jingleBells)/sizeof(int);
  tunes[0].tempo = 60;
  
  tunes[1].melody = firstNoel;
  tunes[1].durations = firstNoelDurations;
  tunes[1].numCount = sizeof(firstNoel)/sizeof(int);  
  tunes[1].tempo = 60;
  
  tunes[2].melody = oHolyNight;
  tunes[2].durations = oHolyNightDurations;
  tunes[2].numCount = sizeof(oHolyNight)/sizeof(int);    
  tunes[2].tempo = 100;
  
  tunes[3].melody = weThreeKings;
  tunes[3].durations = weThreeKingsDurations;
  tunes[3].numCount = sizeof(weThreeKings)/sizeof(int);      
  tunes[3].tempo = 100;
  
  tunes[4].melody = whatChild;
  tunes[4].durations = whatChildDurations;
  tunes[4].numCount = sizeof(whatChild)/sizeof(int);      
  tunes[4].tempo = 100;  
  
  for (int i=0; i<numTunes; i++) {
    int low = N_DS8;
    int high = 0;
    for (int j=0; j<tunes[i].numCount; j++) {
      int freq = tunes[i].melody[j];
      if (freq != 0 && freq<low) low = freq;
      if (freq>high) high = freq;
    }
    tunes[i].high = high;
    tunes[i].low = low;
  }
   
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  
  for (int i=0; i<5; i++) {
     pinMode(outputStartPin + i, OUTPUT);
  } 
  
}

void playTune() {
  int effectNum = random(4);
  lightEffect(effectNum);
  play(toneNum);
  toneNum = (toneNum+1)%5;
  lightEffect(effectNum);  
}

void loop() {
  
  if (continuousMode) {
    playTune();
    delay(2000);
    
  } else {
  
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH) {    
      playTune();
    }
  } 

}
