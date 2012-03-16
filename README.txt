Description:
This module converts normal navigation menus from Drupal into IVR menus in a VoIP script. 

Requirements:
VoIP Drupal 6.x any version > beta5
Tropo, Twilio, Plivo or any other provider that is compatible with VoIP Drupal.

To use this module - 
1. Create navigation menu in admin/build/menus

2. Select the menu in voip_menu admin/voip/voip_menu

3. Using the script:

Option 1. Use the IVR as your default script in admin/voip/call/settings.
  Set the Inbound or Outbound script to voip_menu_ivr

Option 2. Use the script in a custom module.
  Set the script = 'voip_menu_ivr'

4. Call your site at the number configured with your provider or have your site call you with drupal.org/projects/Click2Call
