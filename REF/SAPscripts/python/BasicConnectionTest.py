from pyrfc import Connection

from pprint import pprint
import datetime
from ConfigParser import ConfigParser
import sys

ABAP_SYSTEM_DGE = {
     'user': 'in10c2',
     'passwd': 'Iamroot0!',

     'name': 'DGE',
     'client': '100',
     'ashost': 'cidge10',
     'sysnr': '10',
     'trace': '3'
}

# parameter1 = dict(PARAMETER_NAME='login/min_password_lng')

def main():
    # config = ConfigParser()
    # config.read('sapnwrfcDGE.cfg')
    # params_connection = config._sections['connection']

    conn = Connection(**ABAP_SYSTEM_DGE)
    result = conn.call('PFL_SHOW_PARAMETER_DOCU', PARAMETER_NAME='login/min_password_lng')
    pprint(result)

if __name__ == '__main__':
    main()
