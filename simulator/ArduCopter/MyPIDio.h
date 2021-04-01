#ifndef MYPIDIO_H
#define MYPIDIO_H
#include<iostream>
#include<fstream>
using namespace std;
#include<stdio.h>

class MyPIDio
{
private:
    //static ofstream myfile;
    static const int file = 2;

public:
    /*
     * Yaw
     */
    static void write_to_file_yaw_target(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_yaw_target(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_yaw_target()
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    static void write_to_file_yaw_rate(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_yaw_rate(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_yaw_rate()
    {
        ofstream myfile;
        string filename = "Data_IO_yaw_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    /*
     * Roll
     */
    static void write_to_file_roll_target(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_roll_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_roll_target(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_roll_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_roll_target()
    {
        ofstream myfile;
        string filename = "Data_IO_roll_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    static void write_to_file_roll_rate(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_roll_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_roll_rate(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_roll_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_roll_rate()
    {
        ofstream myfile;
        string filename = "Data_IO_roll_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    /*
     * Pitch
     */

    static void write_to_file_pitch_target(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_pitch_target(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_pitch_target()
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_target_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    static void write_to_file_pitch_rate(string str)
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<str<<",";
    }
    static void write_to_file_pitch_rate(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data <<",";
    }
    static void write_to_file_pitch_rate()
    {
        ofstream myfile;
        string filename = "Data_IO_pitch_rate_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

    /*
     * Position Control
     */
    static void write_to_file_Target_posX(float data)
    {
        ofstream myfile;
        string filename = "Data_IO_Pos_Controller_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<data<<",";
    }
    static void write_to_file_POSX()
    {
        ofstream myfile;
        string filename = "Data_IO_Pos_Controller_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<endl;
    }

};

#endif

