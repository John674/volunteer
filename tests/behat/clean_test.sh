#!/bin/sh
kill `ps wuax | grep 'java -jar /var/lib/selenium/selenium.jar' | grep -v grep | awk '{print $2}'`