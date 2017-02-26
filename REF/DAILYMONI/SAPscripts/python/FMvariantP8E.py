from pyrfc import Connection

from pprint import pprint
import datetime
from ConfigParser import ConfigParser
import sys

ABAP_SYSTEM_P8E = {
     'user': 'in10c2',
     'passwd': 'Open555#',

     'name': 'P8E',
     'client': '008',
     'ashost': 'cip8e47',
     'sysnr': '47',
     'trace': '3'
}

# parameter1 = dict(I_NAME='login/min_password_lng')

def main():
    # config = ConfigParser()
    # config.read('sapnwrfcDGE.cfg')
    # params_connection = config._sections['connection']

    conn = Connection(**ABAP_SYSTEM_P8E)
    result = conn.call('RS_VARIANT_CONTENTS', REPORT='J_2IREXT', VARIANT='AH_2106', MOVE_OR_WRITE='W')
    pprint(result)

if __name__ == '__main__':
    main()
