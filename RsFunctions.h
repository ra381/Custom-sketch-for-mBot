/**
 * @file    mBot_Sketch_2-05-2023
 * @author  Ravinder Singh
 * @version V1.0.7
 * @date    30/04/2023
 * @brief   Description: This file is sample program code for mBot with several extended programs.
 *          To see how this code works, see the following link: https://www.youtube.com/@SinghRavinderOfficial/shorts
 *
 * Function List:
 *    1. void MatrixGoForward();
 *    2. void MatrixTurnRight();
 *    3. void MatrixTurnLeft();
 *    4. void MatrixGoBack();
 *    5. void MatrixStop();
 *    6. void UltrasonicSensorSystem();
 *    7. void linefinderPLUSultrasonic();
 *    8. void SmoothingLightSensor();
 *    9. void RemoveObstacles();
 *    10. void LFS();
 *    11. void Ambulance();
 *    12. void MyTimer();
 *    13. void SecuritySystem();  
 *
 * \par History:
 * <pre>
 *    <Author>         <Time>      <Version>              <Descr>                                   <Video Title>                                           <Link video>`
 * Ravinder Singh    23/12/2022      1.0.0             Build the new.                     mBot just for fun and learn_part 1              https://www.youtube.com/shorts/xNadlQQY688
 * Ravinder Singh    24/12/2022      1.0.2          Add Manual Control.                            Manual Control                         https://www.youtube.com/watch?v=VeWC6Gc5fdU
 * Ravinder Singh    25/12/2022      1.0.1         Add line Finder System.                         Line Follower                          https://www.youtube.com/shorts/842uNd4RHJ8
 * Ravinder Singh    31/12/2022      1.0.2      Add Ultrasonic Sensor System.                    It can't fall down                       https://www.youtube.com/shorts/7WWzslbrNzY
 * Ravinder Singh    07/01/2023      1.0.3      Add linefinderPLUSultrasonic.               Line Follower and Object Avoidance            https://www.youtube.com/shorts/vQcckLoeNX0
 * Ravinder Singh    11/03/2023      1.0.4     Extended line finder + ultrasonic.     Line Follower and Object Avoidance (more than 1)    https://www.youtube.com/shorts/91Z0GxtFA0Y
 * Ravinder Singh    22/04/2023      1.0.5        Add Light Sensor System.                          Light Sensor.                         https://www.youtube.com/shorts/r79G3wO5uHQ
 * Ravinder Singh    25/12/2022      1.0.6          Add AmbulanceSystem.                      mBot goes such as an ambulance.             https://www.youtube.com/shorts/IZOKFJS7Vsk
 * Ravinder Singh    25/12/2022      1.0.6         Add Remove  Obstacles.                          Remove Obstacles.                      https://www.youtube.com/shorts/o6fH0GvQMhY
 * Ravinder Singh    30/04/2023      1.0.7          Added some comments.                                 -                                                     -
 * </pre>
 */


#ifndef RsFunctions_h
#define RsFunctions_h

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//Dichiarazione delle variabili:
MeLEDMatrix ledMx(PORT_4);
unsigned char MatrixArray[16];
unsigned char *arrow_direction;

//Dichiarazione delle Funzioni:
void MatrixGoForward();
void MatrixTurnRight();
void MatrixTurnLeft();
void MatrixGoBack();
void MatrixStop();


//IMPLEMENTAZIONE DELLE FUNZIONI:
void MatrixGoForward(){ // Funzione MatrixGoForward: Gli elementi dell'array caratterizzano diverse forme da visualizzare sulla matrice di LED.
  arrow_direction = new unsigned char[sizeof(MatrixArray)]{0,0,0,0,8,24,56,127,255,127,56,24,8,0,0,0};  // Il valore degli elementi dell'array deve essere compreso tra 0 e 255. [up]
  memcpy(MatrixArray, arrow_direction, sizeof(MatrixArray)); // Copio l'array: memcpy è un comando del c++ che richiede tre parametri: l'array di destinazione, array originale e la dimenzione: numero di byte da copiare. 
  ledMx.drawBitmap(0, 0, sizeof(MatrixArray), MatrixArray); // Questa funzione serve per disegna una bitmap; richiede 4 parametri: le coordinate x, y, la larghezza del vettore e i valori dell'indirizzo dell'array.
}

void MatrixTurnRight(){
  arrow_direction = new unsigned char[sizeof(MatrixArray)]{0,0,24,24,24,24,24,24,24,255,255,126,60,24,0,0};  //right
  memcpy(MatrixArray, arrow_direction, sizeof(MatrixArray));
  ledMx.drawBitmap(0, 0, sizeof(MatrixArray), MatrixArray);
}
  
void MatrixTurnLeft(){
  arrow_direction = new unsigned char[sizeof(MatrixArray)]{0,0,24,60,126,255,255,24,24,24,24,24,24,24,0,0};  //left
  memcpy(MatrixArray, arrow_direction, sizeof(MatrixArray));
  ledMx.drawBitmap(0, 0, sizeof(MatrixArray), MatrixArray);
}

void MatrixGoBack(){
  arrow_direction = new unsigned char[sizeof(MatrixArray)]{0,0,0,0,16,24,28,254,255,254,28,24,16,0,0,0};  //down
  memcpy(MatrixArray, arrow_direction, sizeof(MatrixArray));
  ledMx.drawBitmap(0, 0, sizeof(MatrixArray), MatrixArray);
}

void MatrixStop(){
  arrow_direction = new unsigned char[sizeof(MatrixArray)]{116,84,92,0,64,124,64,0,56,68,68,56,0,124,80,112};  //stop
  memcpy(MatrixArray, arrow_direction, sizeof(MatrixArray));
  ledMx.drawBitmap(0, 0, sizeof(MatrixArray), MatrixArray);
}

#endif
