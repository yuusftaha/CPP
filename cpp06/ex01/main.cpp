#include "Serializer.hpp"

int main() 
{
    Data myData;
    myData.id = 42;
    myData.name = "Arthur Dent";

    std::cout << "--- Orijinal Veri ---" << std::endl;
    std::cout << "Data Adresi: " << &myData << std::endl;
    std::cout << "Data ID    : " << myData.id << std::endl;
    std::cout << "Data Name  : " << myData.name << std::endl;

    uintptr_t rawData = Serializer::serialize(&myData);
    std::cout << "\n--- Serileştirme (Serialization) ---" << std::endl;
    std::cout << "Sayiya donusturulmus adres: " << rawData << std::endl;

    Data* deserializedData = Serializer::deserialize(rawData);
    std::cout << "\n--- Deserileştirme (Deserialization) ---" << std::endl;
    std::cout << "Geri dondurulen adres: " << deserializedData << std::endl;
    std::cout << "Kurtarilan ID        : " << deserializedData->id << std::endl;
    std::cout << "Kurtarilan Name      : " << deserializedData->name << std::endl;

    if (&myData == deserializedData)
        std::cout << "\n[BASARILI] Adresler birbiriyle tamamen eslesiyor!" << std::endl;
    else
        std::cout << "\n[HATA] Adresler uyusmuyor!" << std::endl;

    return 0;
}