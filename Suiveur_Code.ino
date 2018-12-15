const int capteurGauche = 7;
const int capteurCentre = 4;
const int capteurDroit = 3;
bool etatCapteurGauche;
bool etatCapteurCentre;
bool etatCapteurDroit;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentre, INPUT);
  pinMode(capteurDroit, INPUT);
}
void loop()
{
  // put your main code here, to run repeatedly:
  etatCapteurGauche = digitalRead(SensorLeft);
  etatCapteurCentre = digitalRead(SensorMiddle);
  etatCapteurDroit = digitalRead(SensorRight);
  if(etatCapteurCentre) //Si le capteur du centre détecte du noir
  {
    if ((etatCapteurGauche) && (!etatCapteurDroit)) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Serial.println("Tourner à gauche");
    }
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Serial.println("Tourner à droite");
    }
    else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
    {
      Serial.println("Continuer tout droit");
    }
  }
  else //Si le capteur du centre détecte du blanc
  {
    if ((etatCapteurGauche) && (!etatCapteurDroit)) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Serial.println("Tourner à gauche");
    }
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Serial.println("Tourner à droite");
    }
    else //Si les conditions plus hautdne s'appliquent pas, reculer
    {
      Serial.println("Reculer");
    }
  }
}
