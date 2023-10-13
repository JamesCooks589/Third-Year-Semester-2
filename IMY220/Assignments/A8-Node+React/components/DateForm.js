//James Cooks u21654680
// DateForm.js
import React, { useState } from 'react';
import PropTypes from 'prop-types';

const DateForm = ({ onDateChange }) => {
  const [newDate, setNewDate] = useState('');

  const handleDateChange = (e) => {
    const date = e.target.value;
    setNewDate(date);
    onDateChange(date);
  };

  return (
    <div>
      <form>
        <div className="form-group">
          <label htmlFor="newDate">Enter a Date:</label>
          <input
            type="date"
            id="newDate"
            className="form-control"
            value={newDate}
            onChange={handleDateChange}
          />
        </div>
      </form>
    </div>
  );
};

DateForm.propTypes = {
  onDateChange: PropTypes.func.isRequired,
};

export default DateForm;
