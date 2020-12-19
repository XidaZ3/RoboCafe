#ifndef RISORSE_H
#define RISORSE_H

class Risorse
{
    private:
        int temperatura;
        int impastiPizze;

        float litriAcqua;
        int cialdeCaffe;
        float litriLatte;
        int filtriTe;

        static float limiteLitriAcqua, limiteLitriLatte;
        static int limiteImpastiPizze, limiteCialdeCaffe, limiteFiltriTe;

    public:
        Risorse();
        virtual ~Risorse(){};
        Risorse(const Risorse &r);
        Risorse& operator=(const Risorse& s);

        void setTemperatura();

        void rifornituraAcqua();
        void rifornituraCaffe();
        void rifornituraTe();
        void rifornituraLatte();

        void subAcqua(float s);
        void subCaffe(float s);
        void subTe(float s);
        void subLatte(float s);

        enum EccezioneRisorse{
            AcquaInsufficiente,
          CaffeInsufficiente,
          ImpastoPizzaInsufficienti,
          FiltriTeInsufficienti,
          LitriLatteInsufficiente
                };


};

#endif // RISORSE_H
