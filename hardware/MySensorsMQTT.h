#pragma once

#include <deque>
#include <iostream>
#include "MQTT.h"

class MySensorsMQTT : public MQTT
{
public:
	MySensorsMQTT(const int ID, const std::string &IPAddress, const unsigned short usIPPort, const std::string &Username, const std::string &Password, const std::string &CAfilename);
	~MySensorsMQTT(void);
public:
	void on_message(const struct mosquitto_message *message);
	void on_connect(int rc);

	bool AddDevice(const std::string &topicIn, const std::string &topicOut);
private:
	std::string m_TopicInWithoutHash;
	void ProcessMySensorsMessage(const std::string &MySensorsMessage);
	std::string ConvertMessageToMySensorsLine(const std::string &topic, const std::string &qMessage);
	void ConvertMySensorsLineToMessage(const std::string &sendStr, std::string &sTopic, std::string &sPayload);
protected:
	bool StartHardware();
	bool StopHardware();
	void SendHeartbeat();
	void WriteInt(const std::string &sendStr);
};

