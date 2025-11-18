template <typename T, typename V>
class pairs{
        T x;
        V y;
    public:
        void setx(T x){
            this->x=x;
        }
        T getX(){
            return x;
        }
        void sety(V y){
            this->y=y;
        }
        T gety(){
            return y;
        }

};