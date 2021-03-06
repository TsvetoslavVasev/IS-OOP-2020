**Наследяване**

Наследяване е един от основните принципи в ООП. Използваме наследяване, за да изразим клас, като използваме друг, като двата класа имат 'is a' или 'е' връзка(Лабрадорът е куче, кучето е животно и т.н.). Освен това по този начин можем да преизползваме код.

Ако клас А наследява клас Б, то клас а получава всички членове(данни и методи), казваме, че той ги 'наследява'. В случая клас А  е 'базов' или 'родител', а клас Б е 'подклас' или 'дъщерен'.



Наследяването се прави при създаването на клас, съответно:
class Animal {}:

class Dog : public Animal{};

Модификаторът на достъп може да бъде public, protected или private. Ако пропуснете модификатора, то наследяването ще е private .



**Public наследяване** : public членовете на класа-родител стават public членове в дъщерния клас, protected членовете на класа-родител стават protected членове в дъщерния клас, private членовете на класа-родител  не могат да се достъпват директно от дъщерния клас.



**Protected наследяване :** public и protected членовете на класа-родител стават protected членове в дъщерния клас.



**Private наследяване:** public и protected членовете на класа-родител стават private членове в дъщерния клас.

C++ поддържа множествено наследяване, което означава, че клас може да наследява повече от 1 други класа. Това се използва по-рядко, защото създава риск за редица проблеми, като например когато наследяваме  два класа с член-данни с еднакви имена.

class Lion : public Animal, public Predator

**Виртуални методи**

Метод е виртуален, когато преди него използваме 'virtual'
class Vehicle

{

virtual void move()

{

cout << "MOVING"<< endl;

}

}


Когато метод е виртуален ние може да използваме полиморфизъм механизма на С++. Ако клас Car наследи Vehicle, то ние може да override-нем move, като му зададем нова имплементация. По този начин ако след това напишем

Vehicle* car = new Car();

car->move();

то това ще извика move() на Car, а не на Vehicle.

Когато ще override-ваме методи (съща сигнатура, нова имплементация), то трябва методът в класа-родител да е  virtual.

Допълнително за любопитните : http://www.learncpp.com/cpp-tutorial/125-the-virtual-table/


**Интерфейс(абстрактен клас)**

Интерфейс описва поведението на клас без да описва имплементацията на това поведение. Интерфейсовете отговарят на въпроса 'какво?', а не на въпроса 'как?'.



Интерфейсове в С++ - абстрактни класове.  

**Кога клас е абстрактен?**

 Нямаме запазена дума 'abstract'. Клас става абстрактен, когато поне един негов метод е чисто виртуален. Виртуален метод е 'чист', когато след него напишем '=0'.



Използваме абстрактните класове, за да осигурим 'договор', че класът, който го наследява изпълнява поведението на родителя. Не можем да правим инстанции на абстрактен клас. Ако дъщерният клас не имплементира чисто виртуалните методи на класа-родител, то той също става абстрактен и не може да се инстанцира.
