#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Старий інтерфейс
class OldDevice {
public:
    void connect() const {
        cout << "Підключення до старого пристрою" << endl;
    }

    void disconnect() const {
        cout << "Відключення від старого пристрою" << endl;
    }
};

// Новий інтерфейс
class NewDeviceInterface {
public:
    virtual void start() const = 0;
    virtual void stop() const = 0;
    virtual ~NewDeviceInterface() = default;
};

// Адаптер, що робить старий інтерфейс сумісним з новим
class DeviceAdapter : public NewDeviceInterface {
private:
    const OldDevice& oldDevice;

public:
    DeviceAdapter(const OldDevice& device) : oldDevice(device) {}

    void start() const override {
        oldDevice.connect();
    }

    void stop() const override {
        oldDevice.disconnect();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    OldDevice oldDevice;
    DeviceAdapter adaptedDevice(oldDevice);

    cout << "Використання адаптованого пристрою через новий інтерфейс:" << endl;
    adaptedDevice.start();
    adaptedDevice.stop();

}

