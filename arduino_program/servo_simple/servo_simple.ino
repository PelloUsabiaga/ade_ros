
#include <Servo.h>
#include "string.h"

Servo myServo;  

int angle;              
char incoming_byte;


String string_reading;

void setup() {
  myServo.attach(9);   
  Serial.begin(115200); 
  Serial.println("Arduino started!");
  angle = 0;
}

float point_array[60];

int current_trajectory_read_index;
int current_trajectory_length;

void read_positions_array(){
  current_trajectory_read_index = 0;

  float incomming = Serial.parseFloat();

  point_array[current_trajectory_read_index] = incomming;
  current_trajectory_read_index++;

  while (Serial.available()){
    incoming_byte = Serial.read();
    if (incoming_byte == '}'){
      current_trajectory_length = current_trajectory_read_index;
      break;
    }

    incomming = Serial.parseFloat();
    point_array[current_trajectory_read_index] = incomming;
    current_trajectory_read_index++;
  }
}

float times_array[60];

int current_time_read_index;
int current_time_length;

void read_times_array(){
  current_time_read_index = 0;
  incoming_byte = Serial.read(); 

  float incomming = Serial.parseFloat();

  times_array[current_time_read_index] = incomming;
  current_time_read_index++;

  while (Serial.available()){
    incoming_byte = Serial.read();
    if (incoming_byte == '}'){
      current_time_length = current_time_read_index;
      break;
    }

    incomming = Serial.parseFloat();
    times_array[current_time_read_index] = incomming;
    current_time_read_index++;
  }
}

int interpolation_points;

int read_interpolation_data(){
  interpolation_points = Serial.parseInt();
}

void loop() {
  if (Serial.available()){
    incoming_byte = Serial.read();
    if (incoming_byte == '{'){
      read_positions_array();
      read_times_array();
      read_interpolation_data();

      
      unsigned long start_time = millis();

      for(int i = 0; i < current_trajectory_length-1; i++)
      {
        float delta_pos = point_array[i+1] - point_array[i];
        float delta_time = times_array[i+1] - times_array[i];

        for(int j = 0; j < interpolation_points; j++){
          float position = point_array[i] + j*(delta_pos)/interpolation_points;
          myServo.write(position);
          delay(delta_time/interpolation_points);
          Serial.println(position);
        }
      }
      myServo.write(point_array[current_trajectory_length-1]);
      Serial.println(point_array[current_trajectory_length-1]); 

      unsigned long stop_time = millis();
    }  
  }
}
