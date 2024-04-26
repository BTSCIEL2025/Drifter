#define pinDeSortieArduino A2 // ou sur 12   // On va utiliser la broche D12 de l'Arduino Uno

void setup()
{
  // Définition de la broche D12 en "sortie"
  pinMode(pinDeSortieArduino, OUTPUT);
} 

void loop()
{
    tone(pinDeSortieArduino, 488); 
    delay(1000); 
    tone(pinDeSortieArduino, 435); 
    delay(1000); 

}