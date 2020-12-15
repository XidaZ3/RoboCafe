#ifndef RISORSE_H
#define RISORSE_H

class Risorse
{
        private:
        int temperatura;

      float acqua;
      int caffe;
      float latte;
      float te;

        public:
        Risorse();
      virtual ~Risorse(){};
      Risorse(const Risorse &r);
      Risorse& operator=(const Risorse& s);
      void SetTemperatura();
      bool Preleva();
      void Deposita();

};

#endif // RISORSE_H
