class ProductOfNumbers {
private:
    // At most 40,000 numbers can be added. prefix[0] stores 1.
    int prefix[40001];
    int count;

public:
    ProductOfNumbers() : count(0) {
        prefix[0] = 1;
    }

    void add(int num) {
        if (num == 0) {
            count = 0;
            return;
        }

        prefix[count + 1] = prefix[count] * num;
        ++count;
    }

    int getProduct(int k) {
        if (k > count) {
            return 0;
        }

        return prefix[count] / prefix[count - k];
    }
};