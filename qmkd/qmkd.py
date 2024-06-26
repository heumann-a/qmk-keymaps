import sys
import hid
import systemd.daemon

# pls specify your correct IDs
VENDOR_ID     = 0x4335
PRODUCT_ID    = 0x0002

USAGE_PAGE    = 0xFF60
USAGE         = 0x61
REPORT_LENGTH = 32

def get_raw_hid_interface():
    device_interfaces = hid.enumerate(VENDOR_ID, PRODUCT_ID)
    raw_hid_interfaces = [i for i in device_interfaces if i['usage_page'] == USAGE_PAGE and i['usage'] == USAGE]

    if len(raw_hid_interfaces) == 0:
        return None

    interface = hid.Device(path=raw_hid_interfaces[0]['path'])

    print(f"Manufacturer: {interface.manufacturer}")
    print(f"Product: {interface.product}")

    return interface
    
def receive_raw_report(interface):

    try: 
        response_report = interface.read(REPORT_LENGTH, timeout=1000)
        print("Response:" + str(response_report))
    finally:
        pass

def send_raw_report(interface, data):

    request_data = [0x00] * (REPORT_LENGTH + 1) # First byte is Report ID
    request_data[1:len(data) + 1] = data
    request_report = bytes(request_data)

    print("Request:")
    print(request_report)

    try:
        interface.write(request_report)

        response_report = interface.read(REPORT_LENGTH, timeout=1000)

        print("Response:")
        print(response_report)
    finally:
        interface.close()

if __name__ == '__main__':
    interface = get_raw_hid_interface()

    if interface is None:
        print("No device found - Exiting")
        sys.exit(1)
    print('Devices found - Startup complete')
    systemd.daemon.notify('READY=1')

    while True:
        receive_raw_report(interface=interface)