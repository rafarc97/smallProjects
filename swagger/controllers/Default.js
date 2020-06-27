'use strict';

var utils = require('../utils/writer.js');
var Default = require('../service/DefaultService');

module.exports.politicsGET = function politicsGET (req, res, next, id, amountInsured, email, inceptionDate, installmentPayment, clientId) {
  Default.politicsGET(id, amountInsured, email, inceptionDate, installmentPayment, clientId)
    .then(function (response) {
      utils.writeJson(res, response);
    })
    .catch(function (response) {
      utils.writeJson(res, response);
    });
};

module.exports.politicsIdDELETE = function politicsIdDELETE (req, res, next, id) {
  Default.politicsIdDELETE(id)
    .then(function (response) {
      utils.writeJson(res, response);
    })
    .catch(function (response) {
      utils.writeJson(res, response);
    });
};

module.exports.politicsIdGET = function politicsIdGET (req, res, next, id) {
  Default.politicsIdGET(id)
    .then(function (response) {
      utils.writeJson(res, response);
    })
    .catch(function (response) {
      utils.writeJson(res, response);
    });
};

module.exports.politicsPOST = function politicsPOST (req, res, next, politics) {
  Default.politicsPOST(politics)
    .then(function (response) {
      utils.writeJson(res, response);
    })
    .catch(function (response) {
      utils.writeJson(res, response);
    });
};
