#!/bin/sh
# You should install ansible for ability to run this script
export PYTHONUNBUFFERED=1

UPDATE=1
while getopts ":n" opt; do
  case $opt in
    n)
	  UPDATE=0
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

if [ $UPDATE -eq 1 ]
then
  time ansible-playbook -vvvv tests.yml -i 'localhost,' --connection=local
else
  echo "update_dependencies=no"
  time ansible-playbook -vvvv tests.yml -i 'localhost,' --connection=local --extra-vars "update_dependencies=no"
fi