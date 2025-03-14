namespace Maths
{
    template<typename T>
    T Power(const T& a)
    {
        return a * a;
    }

    template<typename T>
    const T& Clamp(const T& value, const T& lowEnd, const T& highEnd)
    {
        // check if its lower than the low end, if it is, return the low end
        // if it isn't check if its greater than the highEnd
        // if its greater than the higher end return the higher end
        // else return the value
        if (value < lowEnd)
        {
            return lowEnd;
        }        
        if (value > highEnd)
        {
            return highEnd;
        }
        return value;
    }

    template<typename T>
    T Normalise(const T& value, const T& minVal, const T& maxVal)
    {
        return (value - minVal)/ (maxVal - minVal);
    }
};
