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


imp = dict(
    RFCINT1=0x7f, # INT1: Integer value (1 byte)
    RFCINT2=0x7ffe, # INT2: Integer value (2 bytes)
    RFCINT4=0x7ffffffe, # INT: integer value (4 bytes)
    RFCFLOAT=1.23456789, # FLOAT

    RFCCHAR1=u'a', # CHAR[1]
    RFCCHAR2=u'ij', # CHAR[2]
    RFCCHAR4=u'bcde', # CHAR[4]
    RFCDATA1=u'k'*50, RFCDATA2=u'l'*50, # CHAR[50] each

    RFCTIME=datetime.time(12,34,56), # TIME
    RFCDATE=datetime.date(2012,10,03), # DATE

    RFCHEX3='\x66\x67\x68' # BYTE[3]: String with 3 hexadecimal values (='fgh')
)

# parameter1 = dict(I_NAME='login/min_password_lng')

def main():
    # config = ConfigParser()
    # config.read('sapnwrfcDGE.cfg')
    # params_connection = config._sections['connection']

    conn = Connection(**ABAP_SYSTEM_DGE)
    result = conn.call('STFC_STRUCTURE', IMPORTSTRUCT=imp)
    pprint(result)

if __name__ == '__main__':
    main()
