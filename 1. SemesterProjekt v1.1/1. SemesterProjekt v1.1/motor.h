/*
 * frem.h
 *
 * Created: 16-06-2014 16:28:24
 *  Author: Bjørn Nørgaard
 */ 

void setPWM( int );/* 0-100% for dutycycle (100%=LAV & 0%=HØJ) */

void setRetning( int ); /* true=tilbage, false=frem*/

void brems( int ); /* aktuel PWM som int */