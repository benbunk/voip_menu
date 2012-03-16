<?php

/**
 *
 * Implementation of hook_form_id_form().
 *
 * @return array
 */
function voip_menu_default_form() {

  $menus = menu_get_names(FALSE);
  if (!is_array($menus)) {
    return 'No Menus available. See the Drupal Menu System documentation for more details.';
  }

  $default = variable_get('voip_menu_selected_menu', 'navigation');
  $default = _check_menu_exists($menus, $default);

  $form['menu_select'] = array(
    '#type' => 'radios',
    '#options' => $menus,
    '#default_value' => $default,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Set default voip server'),
  );

  return $form;
}

/**
 * Implementation of hook_form_id_validate().
 *
 * @param $form
 * @param $form_state
 */
function voip_menu_default_form_validate($form, &$form_state) {

  if (!isset($form_state['values']['menu_select'], $form['menu_select']['#options'])) {
    form_set_error(NULL, 'Incorrect Submission.', TRUE);
  }

  $array_position = is_numeric($form_state['values']['menu_select']) ? $form_state['values']['menu_select'] : NULL;
  $selected = isset($form['menu_select']['#options'][$array_position]) ? $form['menu_select']['#options'][$array_position] : '';

  if (empty($selected)) {
    form_set_error('menu_select', 'No menu specified.');
  }

  // Pass the result along since we already did all the work here in the validator.
  $form_state['menu_selected'] = $selected;
}

/**
 * Implementation of hook_form_id_submit().
 *
 * @param $form
 * @param $form_state
 */
function voip_menu_default_form_submit($form, &$form_state) {
  // Pull the result that validate created.
  $menu_name = $form_state['menu_selected'];
  variable_set('voip_menu_selected_menu', $menu_name);
}
