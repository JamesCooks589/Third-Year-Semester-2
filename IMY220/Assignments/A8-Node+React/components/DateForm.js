import React, { Component } from 'react';
import PropTypes from 'prop-types';

class DateForm extends Component {
  constructor(props) {
    super(props);
    this.state = {
      newDate: '',
    };
  }

  handleDateChange = (e) => {
    const dateWithDashes = e.target.value;
    const dateWithSlashes = dateWithDashes.replace(/-/g, '/');
    this.setState({ newDate: dateWithSlashes });
    this.props.onDateChange(dateWithSlashes);
  };

  render() {
    const { newDate } = this.state;

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
              onChange={this.handleDateChange}
            />
          </div>
        </form>
      </div>
    );
  }
}

DateForm.propTypes = {
  onDateChange: PropTypes.func.isRequired,
};

export default DateForm;
