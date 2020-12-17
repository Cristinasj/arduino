#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
// Esto es un include "pitches.h" pero no le gusta al compilador de tinkercard

// Traductor de notas americanas a españolas (Para "Noche de paz")
// VOY A USAR LA ESCALA 3 y 4 PARA QUE NO SUENE DEMASIADO AGUDO
// SOL es G
// LA es A 
// MI es E 
// RE es D
// SI es B 
// DO es C 

// estas son de la escala 3
#define SOL 193
#define LA 220
#define MI 165
#define SI 247

// estas son de la escala 4 
#define RE 294
#define DO 262



#define ACTIVATED LOW

// NOCHE DE PAZ 

bool cancion = true; 

// VELOCIDAD DE LA CANCIÓN 

int VELOCIDAD = 400; 

// Cantidad de notas de la canción que he hecho 
const int NOTAS = 14; 

int notas[] = {
  SOL, LA, SOL, MI,
  SOL, LA, SOL, MI, 
  RE, RE, SI, 
  DO, DO, SOL
}; 

double duracion[] = {
  1.5, 0.5, 1, 3,
  1.5, 0.5, 1, 3,
  2, 1, 3, 
  2, 1, 3
}; 



const int PIEZO = 11;
const int LED = 13;

const int TECLA_LA = 6;
const int TECLA_MI = 4;
const int TECLA_MI7 = 3;
const int TECLA_RE = 2;


void setup(){
  pinMode(LED, OUTPUT);
  pinMode(TECLA_LA, INPUT_PULLUP);
  digitalWrite(TECLA_LA,HIGH);
  pinMode(TECLA_MI, INPUT_PULLUP);
  digitalWrite(TECLA_MI,HIGH);
  pinMode(TECLA_MI7, INPUT_PULLUP);
  digitalWrite(TECLA_MI7,HIGH);
  pinMode(TECLA_RE, INPUT_PULLUP);
  digitalWrite(TECLA_RE,HIGH);
  
  digitalWrite(LED,LOW);
}



void loop()
{
   while(digitalRead(TECLA_LA) == ACTIVATED)
  {
    tone(PIEZO,LA);
    digitalWrite(LED,HIGH);
  }
  while(digitalRead(TECLA_MI) == ACTIVATED)
  {
    tone(PIEZO,MI);
  }

  while(digitalRead(TECLA_MI7) == ACTIVATED)
  {
    tone(PIEZO,SOL);
  }
  
  while(digitalRead(TECLA_RE) == ACTIVATED)
  {
    tone(PIEZO,RE);
  }

  if(cancion) {
    for (int nota=0; nota <NOTAS; nota++) {
      double tiempo = duracion[nota] * VELOCIDAD;
      tone(11, notas[nota], tiempo);
      double pausa = tiempo * 2;
      delay(pausa);
      noTone(11);
    }
    
  }
  

  noTone(PIEZO);
  digitalWrite(LED,LOW);

}
