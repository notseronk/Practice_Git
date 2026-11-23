#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Forward TC function
float NISTdegCtoMilliVoltsKtype(float tempDegC);  // returns EMF in millivolts

// Inverse TC function
float NISTmilliVoltsToDegCKtype(float tcEMFmV);  // returns temp in degC assuming 0 degC cold jcn

//adc to voltage converter
float adcToVolt(float Voltage_Ref, int Pin);

//kelvin to celsius converter
float KtoC (float K);

float V_ref = 5;// Define reference voltage
float V_supply = 3.3;
float T_0 = 298.15;
float R_0 = 10; // Define Thermistor constants
float B = 3975.0;

int ThermistorPin, ThermocouplePin; //defining thermocouple and thermistor pins
int thermistorCount, thermocoupleCount;

void setup() {
    Serial.begin(9600);
}

void loop() {
    
    float thermistorCount = analogRead(A0);
    float thermocoupleCount = analogRead(A1);

    float Thermistor_V = adcToVolt(V_ref,thermistorCount);
    float Thermocouple_V = adcToVolt(V_ref,thermocoupleCount);

    float R = ((10.0*3.3)/Thermistor_V)-10; //calculates resistance in K_ohms

    float Thermistor_K=pow(((1.0/T_0)+((1.0/B)*log(R/R_0))),-1.0);
    
    float Thermistor_C=KtoC(Thermistor_K);//calculates temperature in kelvin
    

    // Calculate thermocouple temperature in degrees C ( Part c, i - iv)
    float E_TC = (Thermocouple_V-0.35)/54.4;
    float E_TCmV = E_TC*pow(10,3);
    float E_compmV = NISTdegCtoMilliVoltsKtype(Thermistor_C);
    float Thermocouple_C = NISTmilliVoltsToDegCKtype(E_compmV + E_TCmV);
    
    printf("\nE_TCmV = %f\n", E_TC);

    // Output results
    Serial.print("Thermistor temperature (deg C):");
    Serial.println(Thermistor_C, 2);   // 2 decimal places
    Serial.print("Thermocouple temperature (deg C):");
    Serial.println(Thermocouple_C, 2);   // 2 decimal places

    delay (1000);
}



float adcToVolt(float Voltage_ref, int n_adc) //turns ADC value into a voltage that is a fraction of the %V
{
    return (n_adc * Voltage_ref) / 1024.0;
}


float KtoC (float K){ //converts kelvin to celsius

    float C = (K-273.15);

    return C;
}



/* returns EMF in millivolts */
float NISTdegCtoMilliVoltsKtype(float tempDegC)
{
    int i;
    float milliVolts = 0;
    if(tempDegC >= -170 && tempDegC < 0)
    {
        const float coeffs[11] =
        {
            0.000000000000E+00,
            0.394501280250E-01,
            0.236223735980E-04,
            -0.328589067840E-06,
            -0.499048287770E-08,
            -0.675090591730E-10,
            -0.574103274280E-12,
            -0.310888728940E-14,
            -0.104516093650E-16,
            -0.198892668780E-19,
            -0.163226974860E-22
        };
        for (i=0; i<=10; i++)
        {
            milliVolts += coeffs[i] * pow(tempDegC,i);
        }
    }
    else if(tempDegC >= 0 && tempDegC <= 1372)
    {
        const float coeffs[10] =
        {
            -0.176004136860E-01,
            0.389212049750E-01,
            0.185587700320E-04,
            -0.994575928740E-07,
            0.318409457190E-09,
            -0.560728448890E-12,
            0.560750590590E-15,
            -0.320207200030E-18,
            0.971511471520E-22,
            -0.121047212750E-25
        };
        const float a0 =  0.118597600000E+00;
        const float a1 = -0.118343200000E-03;
        const float a2 =  0.126968600000E+03;

        for (i=0; i<=9; i++)
        {
            milliVolts += coeffs[i] * pow(tempDegC,i);
        }

        milliVolts += a0*exp(a1*(tempDegC - a2)*(tempDegC - a2));
    }
    else
    {
        milliVolts = 99E99;
    }
    return milliVolts;
}

// returns temperature in deg C.
float NISTmilliVoltsToDegCKtype(float tcEMFmV)
{

        int i, j;
        float tempDegC = 0;
        const float coeffs[11][3] =
        {
          {0.0000000E+00,  0.000000E+00, -1.318058E+02},
         {2.5173462E+01,  2.508355E+01,  4.830222E+01},
         {-1.1662878E+00,  7.860106E-02, -1.646031E+00},
         {-1.0833638E+00, -2.503131E-01,  5.464731E-02},
         {-8.9773540E-01,  8.315270E-02, -9.650715E-04},
         {-3.7342377E-01, -1.228034E-02,  8.802193E-06},
         {-8.6632643E-02,  9.804036E-04, -3.110810E-08},
         {-1.0450598E-02, -4.413030E-05,  0.000000E+00},
         {-5.1920577E-04,  1.057734E-06,  0.000000E+00},
         {0.0000000E+00, -1.052755E-08,  0.000000E+00}
       };
       if(tcEMFmV >=-5.891 && tcEMFmV <=0 )
       {
           j=0;
       }
       else if (tcEMFmV > 0 && tcEMFmV <=20.644  )
       {
           j=1;
       }
       else if (tcEMFmV > 20.644 && tcEMFmV <=54.886  )
       {
           j=2;
       }
       else
       {
           return 99E9;
       }

       for (i=0; i<=9; i++)
        {
            tempDegC += coeffs[i][j] * pow(tcEMFmV,i);
        }
    return tempDegC;
}

