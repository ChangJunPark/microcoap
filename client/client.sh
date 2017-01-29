#!/bin/bash

echo -e "Coap Client shell\n"
echo -e "GET 127.0.0.1:5683/light\n"
./client GET
echo -e "\n\nPOST 127.0.0.1:5683/light\n"
./client POST 1
echo -e "\n\nPUT 127.0.0.1:5683/light\n"
./client PUT 0
echo -e "\n\nDELETE 127.0.0.1:5683/light\n"
./client DELETE
echo -e "\n\nHEAD 127.0.0.1:5683/light\n"
./client HEAD
echo -e "\n\nOPTIONS 127.0.0.1:5683/light\n"
./client OPTIONS
echo -e "\n\nTRACE 127.0.0.1:5683/light\n"
./client TRACE
