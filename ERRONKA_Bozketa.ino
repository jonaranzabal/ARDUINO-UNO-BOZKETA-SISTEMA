//ALDAGAIAK

//LED-ak
int led1 = 13; //Baiezko botoa LEDa
int led2=12;  //Ezezko botoa LEDa
int ledMartxan=11; //Bozketa martxan LEDa
int ledG=10; //EZEZKO emaitza LEDa
int ledB=8;  //BAIEZKO emaitza LEDa
int ledH=9;  //BERDINKETA LEDa
int ledAmaituta=4; //Bozketa amaituta LEDa
//Pultsagailuak
int yes = 7; //BAIEZKO pultsagailua
int no=6; //EZEZKO pultsagailua
int amaituta=5;//Bozketa AMAITUTA pultsagailua
//BAIEZKO BOTOA
int estadoYes=0; //Egoera
int estadoAntYes=0; //Aurretiko egoera
int contYes=0; //BAIEZKO Kontagailua

//EZEZKO BOTOA
int estadoNo=0; //Egoera
int estadoAntNo=0; //Aurretiko egoera
int contNo=0; //EZEZKO kontagailua

//BOZKETA AMAITUTA
int estadoAmaituta=0;



void setup()
{
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(ledMartxan, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledH, OUTPUT);
  pinMode(ledAmaituta, OUTPUT);
  pinMode(yes, INPUT);
  pinMode(no, INPUT);
  pinMode(amaituta, INPUT);
}

void loop()
{


while(estadoAmaituta==0)  //Bozketa martxan dagoen bitartean:
{
  digitalWrite(ledMartxan,HIGH);  //Bozketa martxan dagoela adierazten duen LEDa piztuko da

  // Pultsagailuak irakurri
  estadoYes = digitalRead(yes);
  estadoNo = digitalRead(no);
  estadoAmaituta = digitalRead(amaituta);

// Tratamendua: Bozketa LEDak piztu  
  digitalWrite(led1, estadoYes);
  digitalWrite(led2, estadoNo);

//Kontagailua BAIEZKOAK


  if(estadoYes != estadoAntYes) // Zapalduta dagoela frogatzen du
  {
    //Piztuta badago kontatu
    if(estadoYes==HIGH)
    {
      contYes++;  //Baiezko botoak kontatu
    }
    estadoAntYes=estadoYes;
    
  }
  
  //Kontagailua EZEZKOKAK
  //Baiezko botoak kontatzeko prozedura bera.
  if(estadoNo != estadoAntNo)
  {
    if(estadoNo==HIGH)
    {
      contNo++;
    }
    estadoAntNo=estadoNo;
  }

}


//AMAIERA botoia sakatzean hurrengo prozedura egin.
if(estadoAmaituta == 1) //AMAIERA botoia sakatuta egon ezkero
{
  digitalWrite(ledMartxan,LOW); //Bozketa martxan dagoela adierazten duen LEDa itzaliko da
  digitalWrite(ledAmaituta,HIGH); //Bozketa amaitu dela adierazten duen LEDa piztuko da
  //Baiezko boto gehiago jaso ezkero LED berdea piztuko da.
  if(contYes>contNo)
  {
    digitalWrite(ledB,HIGH);
  }
  //Berdinketa egon ezkero LED horia piztuko da.
  if(contYes==contNo)
  {
    if(contYes==0)
    {
      digitalWrite(ledMartxan, LOW);
    }
    else
    {
      digitalWrite(ledH,HIGH);
    }
  }
  
  //Ezezko boto gehiago jaso ezkero LED gorria piztuko da.
  if(contYes<contNo)
  {
    digitalWrite(ledG,HIGH);
  }
}
//RESETeko botoia sakatu beharko da bozketa berriro hasi ahal izateko.
}
