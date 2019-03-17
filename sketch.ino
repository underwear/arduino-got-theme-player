int note_B_0 = 247;
int note_Ad_0 = 233;
int note_A_0 = 220;
int note_Gd_0 = 207;
int note_G_0 = 196;
int note_F_0 = 174;

int note_C_1 = 261;
int note_Cd_1 = 277;
int note_D_1 = 293;
int note_Dd_1 = 311;
int note_E_1 = 329;
int note_F_1 = 349;
int note_Fd_1 = 367;
int note_G_1 = 392;
int note_Gd_1 = 415;
int note_A_1 = 440;
int note_Ad_1 = 466;
int note_B_1 = 494;

int note_C_2 = 523;
int note_Cd_2 = 554;
int note_D_2 = 587;
int note_Dd_2 = 622;
int note_E_2 = 659;
int note_F_2 = 698;
int note_Fd_2 = 740;
int note_G_2 = 784;
int note_Gd_2 = 830;
int note_A_2 = 880;
int note_Ad_2 = 932;
int note_B_2 = 988;

int note_C_3 = 1046;

///////

float noteDuration_whole = 1.00;
float noteDuration_half = 0.50;
float noteDuration_quarter = 0.25;
float noteDuration_eighth = 0.125;
float noteDuration_sixteenth = 0.0625; 

class Led {
  public:
    Led (int p) {
      this->pinNum = p;
      this->isTurnedOn = false;
    }
    
    void turnOn() {
      digitalWrite(pinNum, HIGH);
      this->isTurnedOn = true;
    }
    
    void turnOff() {
      digitalWrite(pinNum, LOW);
      this->isTurnedOn = false;
    }
    
    void toggle() {
      if (this->isTurnedOn) {
        this->turnOff();
      } else {
        this->turnOn();
      }
    }
   
  private:
    int pinNum;
    bool isTurnedOn;
};

class Buzzer {
  public:
    Buzzer (int p) {
      this->pinNum = p;
    }

    void playSound (int frequency, int during) {
      tone(this->pinNum, frequency, during);
    }
  private:
    int pinNum;
};

class Player {
  public:
    Player (int wholeDuration, Led * led1, Led * led2, Led * led3, Buzzer * buzzer) {
      this->whole = wholeDuration;
      this->led1 = led1;
      this->led2 = led2;
      this->led3 = led3;
      this->buzzer = buzzer;
    }

    void play (int frequency, float noteDuration) {   
        this->nextLightSignal();
        int duration = int(float(this->whole) * noteDuration);
        this->buzzer->playSound(frequency, duration);
        delay(duration);
    }

  private:
     void nextLightSignal() {
      this->led1->turnOn();
      
      if (int(random(0, 2)) == 1) {
          this->led1->turnOn();
      } else {
          this->led1->turnOff();  
      }

      if (int(random(0, 2)) == 1) {
          this->led2->turnOn();
      } else {
          this->led2->turnOff();  
      }

      if (int(random(0, 2)) == 1) {
          this->led3->turnOn();
      } else {
          this->led3->turnOff();  
      }
    }
  
    int whole;
    Led * led1;
    Led * led2;
    Led * led3;
    Buzzer * buzzer;
    int currentLightSignal = 3;
};

Led led1 = Led(13);
Led led2 = Led(12);
Led led3 = Led(8);
Buzzer buzzer = Buzzer(3);
Player player = Player(1300, &led1, &led2, &led3, &buzzer);



void setup() {
  pinMode(12, OUTPUT); // led
  pinMode(13, OUTPUT); // lded
  pinMode(8, OUTPUT); // led
  pinMode(3, OUTPUT); // buzzer
}

void loop() {
  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_E_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_E_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_E_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_G_1, noteDuration_quarter);
  player.play(note_C_1, noteDuration_quarter);
  player.play(note_E_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  // 2

  player.play(note_G_1, 0.75);

  player.play(note_C_1, 0.75);

  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);
  player.play(note_G_1, noteDuration_half);

  player.play(note_C_1, noteDuration_half);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_quarter);

    // 3


  player.play(note_F_1, 0.75);

  player.play(note_Ad_0, 0.75);

  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_D_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_half);

  player.play(note_Ad_0, noteDuration_half);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_D_1, noteDuration_eighth);

  player.play(note_Gd_0, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_C_1, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_Gd_0, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_C_1, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_quarter);

  // 4

   player.play(note_G_1, 0.75);

  player.play(note_C_1, 0.75);

  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);
  player.play(note_G_1, noteDuration_half);

  player.play(note_C_1, noteDuration_half);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_C_1, noteDuration_eighth);

  player.play(note_D_1, noteDuration_quarter);
  player.play(note_G_0, noteDuration_quarter);
  player.play(note_Ad_0, noteDuration_quarter);

   // 5


  player.play(note_F_1, 0.75);

  player.play(note_Ad_0, 0.75);

  player.play(note_Ad_0, noteDuration_eighth);
  player.play(note_D_1, noteDuration_eighth);
  player.play(note_F_1, noteDuration_half);

  player.play(note_Ad_0, noteDuration_half);
  player.play(note_Dd_1, noteDuration_eighth);
  player.play(note_D_1, noteDuration_eighth);

  player.play(note_Gd_0, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_C_1, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_Gd_0, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_eighth);
  player.play(note_G_0, noteDuration_eighth);

  player.play(note_C_1, noteDuration_quarter);
  player.play(note_F_0, noteDuration_quarter);
  player.play(note_Gd_0, noteDuration_quarter);

  // 6

  player.play(note_G_1, 0.75);

  player.play(note_C_1, 0.75);
  
  delay(5000);
} 
