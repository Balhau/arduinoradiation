# Running

## Sandbox with virtualenv

To run these scripts some libraries are needed. To avoid polluting your host with more and more python packages it is a good practice to create a python sandbox and isolate all the dependencies from your global python instalation. For that python ecosystem provides you with [Virtualenv](https://virtualenv.pypa.io/en/stable/).

So the first step is the installation of python Virtualenv package. For that you just need to run 

    pip install virtualenv


Then you create a new virtual environment and enable it by running both commands

    virtualenv .venv
    source .venv/bin/activate

Notice that you can use other name than .venv. This is just a very used convention I decided to follow, but any name can be provided.



Now that we have the python sandbox created and loaded into our runtime we just need to install the needed python packages

    pip install paho-mqtt
    pip install pyserial


Now you can send your radiation ticks into your mqtt server by running

    python radiation-mqtt-producer.py

And receive the messages from the topic with

    python radiation-mqtt-client.py
