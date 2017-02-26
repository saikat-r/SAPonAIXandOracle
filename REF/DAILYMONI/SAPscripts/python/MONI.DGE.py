from pyrfc import Connection

from pprint import pprint
import datetime
from datetime import datetime
from datetime import date
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

cr_date = date(2015, 05, 12)
for attr in [ 'year', 'month', 'day' ]:
      print attr, ':', getattr(d, attr)
#mydate1 = str(cr_date)
#mydate1 = cr_date.strftime('%d.%m.%Y')
#mydate2 = datetime.strptime(cr_date, '%Y-%m-%d %H:%M:%S.%f').strftime('%m/%d/%Y')
#mydatestrng='2015-05-12'
#mydate1=datetime.date(*map(int, mydatestrng.split('-')))
#mydate2=datetime.strptime('2011-03-07','%Y-%m-%d')


# parameter1 = dict(I_NAME='login/min_password_lng')

def main():
    # config = ConfigParser()
    # config.read('sapnwrfcDGE.cfg')
    # params_connection = config._sections['connection']

    conn = Connection(**ABAP_SYSTEM_DGE)
    result = conn.call('SWNC_COLLECTOR_GET_AGGREGATES', COMPONENT='TOTAL', ASSIGNDSYS='DGH', PERIODTYPE='D', PERIODSTRT='12.05.2015')
    pprint(result)

if __name__ == '__main__':
    main()
