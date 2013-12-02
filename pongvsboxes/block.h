class block
{
    public:

        int lives, widthB, heightB;
        float x, y, z;
        // Default constructor
        block();

        block(float a, float b, float c, int l, int wB, int hB);

        int hits();
};
