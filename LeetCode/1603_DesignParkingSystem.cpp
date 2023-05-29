class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) 
    :Small(small), Medium(medium), Big(big)
    {
    }
    
    bool addCar(int carType) {
        if(carType==3){
            if(Small==0)
                return false;
             Small--;
                 return true;
        }
        else if(carType==2){
            if(Medium==0)
                return false;
            Medium--;
                return true;
        }
        else
        {
            if(Big==0)
                return false;
            Big--;
                return true;
        }
    }
    private:
    int Small, Medium, Big;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
