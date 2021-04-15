using System;

namespace Parcial01
{
    static class generatorPIN
    {
        private static Random generatorRandom = new Random();

        public static string generatephonenumber()
        {
            int partOne, partTwo;
            partOne = generatorRandom.Next(6000, 8000);
            partTwo = generatorRandom.Next(1000, 10000);

            string nphone = $"{partOne}-{partTwo}";
            Console.WriteLine("El numero de Iphone otrogado es {i}", nphone);

            return nphone;
        }

        public static string generatecode()
        {
            int continuar;
            string codegeneraterd = "";

            do
            {
                Console.WriteLine("_CODIGO");
                Console.WriteLine("1- PIN");
                continuar = Convert.ToInt32(Console.ReadLine());

                switch (continuar)
                {
                    case 1:
                    codegeneraterd = Convert.ToString(generatorRandom.Next(1000,10000));
                    Console.WriteLine("EL PIN es {i}", codegeneraterd);
                    break;

                    default:
                    Console.WriteLine("Digite el numero bien");
                    break;
                }
            }while (continuar < 1);

            return codegeneraterd;

        }
        public static double calcularcostoSms(string msg)
                    {
                        int totalcaracteres = msg.Length;
                        int entero = totalcaracteres / 20;
                        if(totalcaracteres % 20 != 0)
                        {
                           return (entero + 1) * 0.05;     
                        }
                        return entero * 0.05;
                    }
        
        public static bool validationDUI(string dui)
        {
            const string digitos = "0123456789";

            if(dui.Length != 10)
            {
                Console.WriteLine("numero de dui invalido.");
                return false;
            }

            for(int i = 0; i < dui.Length; i++)
            {
                if((i == 8 && dui[i] != '-') || (i != 8 && !digitos.Contains(dui[i])))
                {
                    Console.WriteLine("Numero de DUI invalido.");
                    return false;
                }
            }
        }
        public static bool validationnit(string nit)
        {
            const string digitos = "0123456789";

            if (nit.Length != 17)
            {
                Console.WriteLine("numero de NIT invalido.");
                return false;
            }
            
            for(int i = 0; i < nit.Length; i++)
            {
                if(((i == 4 || i == 11 || i == 15) && nit[i] != "-") || (i != 4 && i!= 11 && i!= 15 ! digitos.Contains(nit[i])))
                {
                    Console.WriteLine("Numero de DUI invalido.");
                    return false;
                }
            }
        }

        public static string generatorpasword(int cantidad)
        {
            const string chars = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789";
            var stringchars = new char[cantidad];

            for(var i = 0; i < stringchars.Length; i++)
            {
                stringchars[i] = chars[generatorRandom.Next(chars.Length)];

            }
            return new string(stringchars);
        }
        public static string generatorappleID()
        {
            string appleID = $"{generatorpasword(cantidad 8)}@icloud.com";
            Console.WriteLine("su apple ID es{0}", appleID);
            return appleID; 
        }

    }
}
