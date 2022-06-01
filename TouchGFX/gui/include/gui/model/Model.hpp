#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
private:
    bool useRandom;
    int tickCounter;
    int modifier;
    int peakValue;
    int value;
};

#endif // MODEL_HPP
