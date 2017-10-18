#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>

using namespace rapidjson;
/*int main() {
	// 1. Parse a JSON string into DOM.
	const char* json = "{\"Info\":[{\"lots\":10,\"order_algorithm\":\"01\",\"buy_close\":9000,\"spread_shift\":0,\"position_b_sell\":0,\"position_a_buy_today\":0,\"position_a_buy_yesterday\":0,\"sell_open\":-9000,\"list_instrument_id\":[\"rb1705\",\"rb1701\"],\"position_b_buy_today\":0,\"buy_open\":-9000,\"position_a_sell_yesterday\":0,\"strategy_id\":\"02\",\"position_b_buy\":0,\"a_wait_price_tick\":1,\"trade_model\":\"boll_reversion\",\"b_wait_price_tick\":0,\"sell_close\":9000,\"only_close\":0,\"order_action_limit\":400,\"is_active\":1,\"lots_batch\":1,\"position_a_sell\":0,\"position_b_buy_yesterday\":0,\"user_id\":\"063802\",\"position_a_buy\":0,\"trader_id\":\"1601\",\"position_a_sell_today\":0,\"stop_loss\":0,\"position_b_sell_today\":0,\"position_b_sell_yesterday\":0,\"on_off\":0},{\"lots\":20,\"order_algorithm\":\"02\",\"buy_close\":9000,\"spread_shift\":0,\"position_b_sell\":0,\"position_a_buy_today\":0,\"position_a_buy_yesterday\":0,\"sell_open\":-9000,\"list_instrument_id\":[\"ni1705\",\"ni1701\"],\"position_b_buy_today\":0,\"buy_open\":-9000,\"position_a_sell_yesterday\":0,\"strategy_id\":\"01\",\"position_b_buy\":0,\"a_wait_price_tick\":1,\"trade_model\":\"boll_reversion\",\"b_wait_price_tick\":0,\"sell_close\":9000,\"only_close\":0,\"order_action_limit\":400,\"is_active\":1,\"lots_batch\":1,\"position_a_sell\":0,\"position_b_buy_yesterday\":0,\"user_id\":\"063802\",\"position_a_buy\":0,\"trader_id\":\"1601\",\"position_a_sell_today\":0,\"stop_loss\":0,\"position_b_sell_today\":0,\"position_b_sell_yesterday\":0,\"on_off\":0}],\"MsgSendFlag\":0,\"MsgErrorReason\":\"IDorpassworderror\",\"MsgRef\":1,\"MsgType\":3,\"MsgResult\":0}";
	//std::cout << json << std::endl;
	//std::cout << "\n" << std::endl;
	std::cout << "|==================|" << std::endl;
	std::cout << "||rapidjson output||" << std::endl;
	std::cout << "|==================|" << std::endl;
	Document doc;
	doc.Parse(json);

	// 2. Modify it by DOM.
	Value& s = doc["MsgSendFlag"];
	s.SetInt(s.GetInt() + 1);

	Value& infoArray = doc["Info"];
	if (infoArray.IsArray()) {
		for (int i = 0; i < infoArray.Size(); i++) {
			const Value& object = infoArray[i];
			int lots = object["lots"].GetInt();
			std::string order_algorith = object["order_algorithm"].GetString();
			std::cout << "int lots = " << lots << std::endl;
			std::cout << "string order_algorithm = " << order_algorith << std::endl;
			const Value& info_object = object["list_instrument_id"];
			if (info_object.IsArray()) {
				for (int j = 0; j < info_object.Size(); j++) {
					std::string instrumen = info_object[j].GetString();
					std::cout << "instrument[" << j << "] = " << instrumen << std::endl;
				}
			}
		}
	}

	// 3. Stringify the DOM
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	doc.Accept(writer);
	std::cout << buffer.GetString() << std::endl;
	system("pause");
	return 0;
}*/