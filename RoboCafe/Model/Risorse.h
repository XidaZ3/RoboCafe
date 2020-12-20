#ifndef RISORSE_H
#define RISORSE_H

class Risorse
{
    private:
        int temperatura,impastiPizze,cialdeCaffe, filtriTe;
        float litriAcqua,litriLatte;

        static const float limiteLitriAcqua, limiteLitriLatte;
        static const int limiteImpastiPizze, limiteCialdeCaffe, limiteFiltriTe;

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
        void rifornituraPizza();

        void subAcqua(float s);
        void subCaffe(int s);
        void subTe(int s);
        void subLatte(float s);
        void subPizza(int s);


};



#endif // RISORSE_H
